
import "./App.css";

function App() {
  return (
    <>
      <nav className="navbar">
        <h2>MyPortfolio</h2>
        <div>
          <a href="#home">Home</a>
          <a href="#about">About</a>
          <a href="#projects">Projects</a>
          <a href="#contact">Contact</a>
        </div>
      </nav>

      <section id="home" className="hero">
        <p>Hello, I'm</p>
        <h1>Muhammad Rustian Al-farizi</h1>
        <h2>Web Developer</h2>
        <p>
          Saya sedang belajar membuat website
          dan mengembangkan kemampuan programming.
        </p>
        <a href="#projects" className="btn">
          Lihat Project
        </a>
      </section>

      <section id="about">
        <h2>About Me</h2>
        <p>
          Saya tertarik dengan dunia teknologi,
          pemrograman, dan pengembangan website.
        </p>
      </section>

      <section id="projects">
        <h2>My Projects</h2>
        <div className="project-card">
          <h3>Lost & Found UNPAM</h3>
          <p>
            Website untuk membantu mahasiswa
            melaporkan barang hilang dan ditemukan.
          </p>
        </div>
      </section>

      <section id="contact">
        <h2>Contact Me</h2>
        <p>Email: fariz200803@gmail.com</p>
        <p>GitHub: github.com/username</p>
      </section>

      <footer>
        © 2026 My Portfolio
      </footer>
    </>
  );
}

export default App;
