require('dotenv').config();

const path = require('path');
const express = require('express');
const { createClient } = require('@supabase/supabase-js');

const app = express();
const port = process.env.PORT || 3000;
const tableName = 'items';
const allowedStatuses = new Set(['lost', 'found', 'returned']);
const supabaseUrl = process.env.SUPABASE_URL;
const supabaseKey = process.env.SUPABASE_SERVICE_ROLE_KEY;
const supabase = supabaseUrl && supabaseKey
  ? createClient(supabaseUrl, supabaseKey)
  : null;

let demoItems = [
  {
    id: 'demo-1',
    title: 'Tumbler stainless warna sage',
    description: 'Ada stiker kecil berbentuk matahari di bagian bawah.',
    category: 'Botol minum',
    location: 'Perpustakaan, lantai 2',
    status: 'found',
    contact: 'Nadia - BEM',
    created_at: '2026-10-29T08:30:00.000Z'
  },
  {
    id: 'demo-2',
    title: 'Kartu mahasiswa atas nama Dimas',
    description: 'Ditemukan dekat ruang kelas 3.04.',
    category: 'Kartu & dokumen',
    location: 'Gedung A, lantai 3',
    status: 'found',
    contact: 'Raka - 0812 0000 1234',
    created_at: '2026-10-28T13:15:00.000Z'
  },
  {
    id: 'demo-3',
    title: 'Earbuds putih dalam case',
    description: 'Terakhir terlihat setelah kelas malam hari Senin.',
    category: 'Elektronik',
    location: 'Selasar Gedung C',
    status: 'lost',
    contact: 'Alya - 0813 0000 5678',
    created_at: '2026-10-27T11:00:00.000Z'
  },
  {
    id: 'demo-4',
    title: 'Payung lipat biru navy',
    description: 'Tertinggal di area parkir motor dekat gerbang.',
    category: 'Aksesori',
    location: 'Parkiran motor, gerbang utama',
    status: 'returned',
    contact: 'Dito - 0812 0000 4321',
    created_at: '2026-10-25T06:45:00.000Z'
  }
];

app.use(express.json({ limit: '20kb' }));
app.use(express.static(path.join(__dirname, 'public')));

function normalizeItem(body) {
  const fields = ['title', 'description', 'category', 'location', 'status', 'contact'];
  const item = {};

  for (const field of fields) {
    item[field] = typeof body[field] === 'string' ? body[field].trim() : '';
  }

  if (!item.title || !item.category || !item.location || !item.contact) {
    return { error: 'Judul, kategori, lokasi, dan kontak wajib diisi.' };
  }

  if (!allowedStatuses.has(item.status)) {
    return { error: 'Status laporan tidak valid.' };
  }

  if (item.title.length > 100 || item.description.length > 500 || item.contact.length > 100) {
    return { error: 'Judul, deskripsi, atau kontak melebihi batas karakter.' };
  }

  return { item };
}

function databaseUnavailable(res) {
  return res.status(503).json({
    error: 'Database belum terhubung. Isi SUPABASE_URL dan SUPABASE_SERVICE_ROLE_KEY.'
  });
}

app.get('/api/items', async (req, res) => {
  if (!supabase) {
    if (process.env.VERCEL) return databaseUnavailable(res);
    res.set('X-Data-Mode', 'demo');
    return res.json(demoItems.slice().sort((a, b) => b.created_at.localeCompare(a.created_at)));
  }

  const { data, error } = await supabase.from(tableName).select('*').order('created_at', { ascending: false });
  if (error) return res.status(500).json({ error: 'Gagal mengambil laporan barang.' });
  return res.json(data);
});

app.get('/api/items/:id', async (req, res) => {
  if (!supabase) {
    if (process.env.VERCEL) return databaseUnavailable(res);
    const item = demoItems.find((entry) => entry.id === req.params.id);
    return item ? res.json(item) : res.status(404).json({ error: 'Laporan tidak ditemukan.' });
  }

  const { data, error } = await supabase.from(tableName).select('*').eq('id', req.params.id).maybeSingle();
  if (error) return res.status(500).json({ error: 'Gagal mengambil laporan barang.' });
  return data ? res.json(data) : res.status(404).json({ error: 'Laporan tidak ditemukan.' });
});

app.post('/api/items', async (req, res) => {
  const result = normalizeItem(req.body || {});
  if (result.error) return res.status(400).json({ error: result.error });

  if (!supabase) {
    if (process.env.VERCEL) return databaseUnavailable(res);
    const item = { ...result.item, id: `demo-${Date.now()}`, created_at: new Date().toISOString() };
    demoItems = [item, ...demoItems];
    return res.status(201).json(item);
  }

  const { data, error } = await supabase.from(tableName).insert(result.item).select().single();
  if (error) return res.status(500).json({ error: 'Gagal menyimpan laporan barang.' });
  return res.status(201).json(data);
});

app.put('/api/items/:id', async (req, res) => {
  const result = normalizeItem(req.body || {});
  if (result.error) return res.status(400).json({ error: result.error });

  if (!supabase) {
    if (process.env.VERCEL) return databaseUnavailable(res);
    const index = demoItems.findIndex((entry) => entry.id === req.params.id);
    if (index === -1) return res.status(404).json({ error: 'Laporan tidak ditemukan.' });
    demoItems[index] = { ...demoItems[index], ...result.item };
    return res.json(demoItems[index]);
  }

  const { data, error } = await supabase.from(tableName).update(result.item).eq('id', req.params.id).select().maybeSingle();
  if (error) return res.status(500).json({ error: 'Gagal memperbarui laporan barang.' });
  return data ? res.json(data) : res.status(404).json({ error: 'Laporan tidak ditemukan.' });
});

app.delete('/api/items/:id', async (req, res) => {
  if (!supabase) {
    if (process.env.VERCEL) return databaseUnavailable(res);
    const exists = demoItems.some((entry) => entry.id === req.params.id);
    if (!exists) return res.status(404).json({ error: 'Laporan tidak ditemukan.' });
    demoItems = demoItems.filter((entry) => entry.id !== req.params.id);
    return res.status(204).end();
  }

  const { data, error } = await supabase.from(tableName).delete().eq('id', req.params.id).select('id').maybeSingle();
  if (error) return res.status(500).json({ error: 'Gagal menghapus laporan barang.' });
  return data ? res.status(204).end() : res.status(404).json({ error: 'Laporan tidak ditemukan.' });
});

app.use('/api', (req, res) => res.status(404).json({ error: 'Endpoint tidak ditemukan.' }));

if (require.main === module) {
  app.listen(port, () => console.log(`UNPAM Lost & Found berjalan di http://localhost:${port}`));
}

module.exports = app;