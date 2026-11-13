
import "./Hero.css";

function Hero() {
  return (
    <section className="hero" id="home">
      <div className="hero-content">

        <p className="hero-greeting">
          HELLO, I'M
        </p>

        <h1>
          Andi <span>Developer.</span>
        </h1>

        <h2>
          Aspiring Frontend Developer
        </h2>

        <p className="hero-description">
          Saya tertarik dengan dunia teknologi
          dan pengembangan website. Saat ini saya
          sedang mengembangkan kemampuan dalam
          HTML, CSS, JavaScript, dan React.
        </p>

        <div className="hero-buttons">
          <a href="#projects" className="btn-primary">
            View Projects
          </a>

          <a href="#contact" className="btn-outline">
            Contact Me
          </a>
        </div>

      </div>

      <div className="hero-image">
        <div className="profile-placeholder">
          YOUR PHOTO
        </div>
      </div>
    </section>
  );
}

export default Hero;
