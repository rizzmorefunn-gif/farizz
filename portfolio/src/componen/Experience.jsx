
import "./Experience.css";

const experiences = [
  {
    year: "2026",
    title: "Learning React & Vite",
    description:
      "Mempelajari pengembangan website menggunakan React, Vite, JavaScript, dan CSS.",
    category: "Learning",
  },
  {
    year: "2026",
    title: "Lost & Found UNPAM",
    description:
      "Mengembangkan website untuk membantu mahasiswa melaporkan barang hilang dan ditemukan.",
    category: "Personal Project",
  },
  {
    year: "2026",
    title: "Learning Python",
    description:
      "Mempelajari dasar Python, perulangan, fungsi, dan penyimpanan data menggunakan CSV.",
    category: "Learning",
  },
];

function Experience() {
  return (
    <section className="experience" id="experience">
      <div className="experience-heading">
        <p>MY JOURNEY</p>
        <h2>Experience & Learning</h2>
        <span>
          Perjalanan saya dalam mempelajari
          teknologi dan programming.
        </span>
      </div>

      <div className="timeline">
        {experiences.map((item, index) => (
          <div className="timeline-item" key={index}>
            <div className="timeline-dot"></div>

            <div className="timeline-card">
              <span className="timeline-year">
                {item.year}
              </span>

              <span className="timeline-category">
                {item.category}
              </span>

              <h3>{item.title}</h3>

              <p>{item.description}</p>
            </div>
          </div>
        ))}
      </div>
    </section>
  );
}

export default Experience;
