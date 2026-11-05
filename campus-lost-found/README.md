# UNPAM Lost & Found

Aplikasi CRUD laporan barang hilang dan ditemukan untuk lingkungan kampus. Frontend menggunakan HTML, CSS, dan JavaScript; backend menggunakan Express; Supabase PostgreSQL menyimpan data permanen.

## Jalankan lokal

1. Pasang Node.js 18 atau lebih baru.
2. Buka folder proyek di terminal, lalu jalankan `npm install`.
3. Jalankan `npm run dev`.
4. Buka `http://localhost:3000`.

Tanpa konfigurasi Supabase, aplikasi lokal memakai data demo di memori. Perubahan data demo akan hilang saat server dimulai ulang.

## Hubungkan database Supabase

1. Buat proyek di Supabase.
2. Buka **SQL Editor**, lalu jalankan:

```sql
create table public.items (
  id uuid primary key default gen_random_uuid(),
  title text not null,
  description text not null default '',
  category text not null,
  location text not null,
  status text not null check (status in ('lost', 'found', 'returned')),
  contact text not null,
  created_at timestamptz not null default now()
);
```

3. Salin `.env.example` menjadi `.env`, lalu isi `SUPABASE_URL` dan `SUPABASE_SERVICE_ROLE_KEY` dari pengaturan API proyek Supabase.
4. Mulai ulang `npm run dev`. Kunci service role hanya dipakai server; jangan taruh di frontend atau commit file `.env`.

## Deploy ke Vercel

1. Push folder proyek ke repository GitHub.
2. Di Vercel pilih **Add New Project**, lalu import repository tersebut.
3. Di **Project Settings → Environment Variables**, tambahkan `SUPABASE_URL` dan `SUPABASE_SERVICE_ROLE_KEY` dengan nilai dari Supabase.
4. Deploy. Setiap kali mengubah environment variable, jalankan deployment baru.
5. Buka URL deployment dan uji tambah, ubah, hapus, serta pencarian laporan.

Vercel menjalankan `index.js` sebagai aplikasi Express. Di Vercel, database Supabase wajib dikonfigurasi karena memori function tidak persisten.

## Endpoint CRUD

| Method | Endpoint | Fungsi |
| --- | --- | --- |
| GET | `/api/items` | Daftar laporan |
| GET | `/api/items/:id` | Detail laporan |
| POST | `/api/items` | Tambah laporan |
| PUT | `/api/items/:id` | Ubah laporan |
| DELETE | `/api/items/:id` | Hapus laporan |

## Catatan demo

Versi ini belum memiliki login atau pembatasan hak akses. Semua pengunjung dapat membuat, mengubah, dan menghapus laporan; tambahkan autentikasi sebelum digunakan untuk data kampus sungguhan. Foto header memerlukan koneksi internet.