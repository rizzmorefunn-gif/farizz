const itemsGrid = document.querySelector('#items-grid');
const emptyState = document.querySelector('#empty-state');
const resultCount = document.querySelector('#result-count');
const searchInput = document.querySelector('#search-input');
const reportDialog = document.querySelector('#report-dialog');
const reportForm = document.querySelector('#report-form');
const formError = document.querySelector('#form-error');
const toast = document.querySelector('#toast');
const dataNote = document.querySelector('#data-note');

let items = [];
let activeFilter = 'all';
let toastTimer;

const labels = { lost: 'Hilang', found: 'Ditemukan', returned: 'Sudah kembali' };

function escapeHtml(value = '') {
  return String(value).replace(/[&<>"']/g, (character) => ({
    '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;'
  })[character]);
}

function formatDate(value) {
  return new Intl.DateTimeFormat('id-ID', { day: 'numeric', month: 'short' }).format(new Date(value));
}

function showToast(message) {
  toast.textContent = message;
  toast.classList.add('is-visible');
  clearTimeout(toastTimer);
  toastTimer = setTimeout(() => toast.classList.remove('is-visible'), 2800);
}

function visibleItems() {
  const query = searchInput.value.trim().toLocaleLowerCase('id-ID');
  return items.filter((item) => {
    const matchesStatus = activeFilter === 'all' || item.status === activeFilter;
    const searchable = [item.title, item.category, item.location, item.description].join(' ').toLocaleLowerCase('id-ID');
    return matchesStatus && searchable.includes(query);
  });
}

function renderItems() {
  const shown = visibleItems();
  resultCount.textContent = `${shown.length} laporan`;
  emptyState.hidden = shown.length > 0;

  itemsGrid.innerHTML = shown.map((item, index) => `
    <article class="item-card" style="animation-delay:${Math.min(index * 45, 180)}ms">
      <div class="item-topline">
        <span class="status-label status-${escapeHtml(item.status)}">${escapeHtml(labels[item.status] || 'Laporan')}</span>
        <span class="category-label">${escapeHtml(item.category)} · ${escapeHtml(formatDate(item.created_at))}</span>
      </div>
      <h3>${escapeHtml(item.title)}</h3>
      <p class="item-description">${escapeHtml(item.description || 'Tidak ada keterangan tambahan.')}</p>
      <p class="item-location"><span class="location-mark" aria-hidden="true">⌖</span><span>${escapeHtml(item.location)}</span></p>
      <div class="item-footer">
        <span class="contact-line" title="${escapeHtml(item.contact)}">${escapeHtml(item.contact)}</span>
        <div class="card-actions">
          <button class="small-action" data-action="edit" data-id="${escapeHtml(item.id)}" type="button">Ubah</button>
          <button class="small-action delete" data-action="delete" data-id="${escapeHtml(item.id)}" type="button">Hapus</button>
        </div>
      </div>
    </article>
  `).join('');
}

async function loadItems() {
  try {
    const response = await fetch('/api/items');
    const data = await response.json();
    if (!response.ok) throw new Error(data.error || 'Laporan gagal dimuat.');
    items = data;
    dataNote.hidden = Boolean(response.headers.get('x-data-mode') !== 'demo');
    renderItems();
  } catch (error) {
    itemsGrid.innerHTML = '';
    emptyState.hidden = false;
    emptyState.querySelector('h3').textContent = 'Laporan belum bisa dimuat';
    emptyState.querySelector('p').textContent = error.message;
    resultCount.textContent = '';
  }
}

function openCreateDialog() {
  reportForm.reset();
  document.querySelector('#item-id').value = '';
  document.querySelector('#dialog-title').textContent = 'Buat laporan';
  document.querySelector('#submit-report').innerHTML = 'Kirim laporan <span aria-hidden="true">↗</span>';
  formError.textContent = '';
  reportDialog.showModal();
  document.querySelector('#item-title').focus();
}

function openEditDialog(item) {
  reportForm.reset();
  document.querySelector('#item-id').value = item.id;
  document.querySelector('#item-title').value = item.title;
  document.querySelector('#item-status').value = item.status;
  document.querySelector('#item-category').value = item.category;
  document.querySelector('#item-location').value = item.location;
  document.querySelector('#item-description').value = item.description || '';
  document.querySelector('#item-contact').value = item.contact;
  document.querySelector('#dialog-title').textContent = 'Ubah laporan';
  document.querySelector('#submit-report').textContent = 'Simpan perubahan';
  formError.textContent = '';
  reportDialog.showModal();
  document.querySelector('#item-title').focus();
}

document.querySelector('#open-create').addEventListener('click', openCreateDialog);
document.querySelector('#close-dialog').addEventListener('click', () => reportDialog.close());
document.querySelector('#cancel-dialog').addEventListener('click', () => reportDialog.close());
searchInput.addEventListener('input', renderItems);

document.querySelectorAll('.filter-button').forEach((button) => {
  button.addEventListener('click', () => {
    activeFilter = button.dataset.filter;
    document.querySelectorAll('.filter-button').forEach((entry) => entry.classList.toggle('is-active', entry === button));
    renderItems();
  });
});

itemsGrid.addEventListener('click', async (event) => {
  const button = event.target.closest('button[data-action]');
  if (!button) return;
  const item = items.find((entry) => entry.id === button.dataset.id);
  if (!item) return;

  if (button.dataset.action === 'edit') {
    openEditDialog(item);
    return;
  }

  if (!window.confirm(`Hapus laporan "${item.title}"?`)) return;
  try {
    const response = await fetch(`/api/items/${encodeURIComponent(item.id)}`, { method: 'DELETE' });
    const result = response.status === 204 ? {} : await response.json();
    if (!response.ok) throw new Error(result.error || 'Laporan gagal dihapus.');
    await loadItems();
    showToast('Laporan berhasil dihapus.');
  } catch (error) {
    showToast(error.message);
  }
});

reportForm.addEventListener('submit', async (event) => {
  event.preventDefault();
  formError.textContent = '';
  const id = document.querySelector('#item-id').value;
  const formData = new FormData(reportForm);
  const payload = Object.fromEntries(formData.entries());
  const submitButton = document.querySelector('#submit-report');
  submitButton.disabled = true;

  try {
    const response = await fetch(id ? `/api/items/${encodeURIComponent(id)}` : '/api/items', {
      method: id ? 'PUT' : 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(payload)
    });
    const result = response.status === 204 ? {} : await response.json();
    if (!response.ok) throw new Error(result.error || 'Laporan gagal disimpan.');
    reportDialog.close();
    await loadItems();
    showToast(id ? 'Perubahan berhasil disimpan.' : 'Laporan berhasil dikirim.');
  } catch (error) {
    formError.textContent = error.message;
  } finally {
    submitButton.disabled = false;
  }
});

document.addEventListener('keydown', (event) => {
  if ((event.metaKey || event.ctrlKey) && event.key.toLowerCase() === 'k') {
    event.preventDefault();
    searchInput.focus();
  }
});

loadItems();