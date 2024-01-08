document.addEventListener('DOMContentLoaded', () => {
    // Animation for the welcome Texts
    const welcomeTexts = document.querySelectorAll('#home p, #home h2');

    welcomeTexts.forEach(text => {
        text.style.opacity = '0';
    });

    setTimeout(() => {
        welcomeTexts.forEach(text => {
            text.style.opacity = '1';
            text.style.transition = 'opacity 1s ease-in-out';
        });
    }, 300);
});
// Smooth Scrolling for Navigation Links
const navLinks = document.querySelectorAll('nav a');

navLinks.forEach(link => {
    link.addEventListener('click', (event) => {
        event.preventDefault();
        const targetId = link.getAttribute('href').substring(1);
        const targetSection = document.getElementById(targetId);

        window.scrollTo({
            top: targetSection.offsetTop - 50, 
            behavior: 'smooth'
        });
    });
});


document.addEventListener('DOMContentLoaded', () => {
    const backToTopButton = document.getElementById('back-to-top-btn');

    window.addEventListener('scroll', () => {
        if (document.body.scrollTop > 20 || document.documentElement.scrollTop > 20) {
            backToTopButton.style.display = 'block';
        } else {
            backToTopButton.style.display = 'none';
        }
    });
})


document.addEventListener('DOMContentLoaded', () => {
    const menuIcon = document.querySelector('.menu-icon');
    const navLinks = document.querySelector('nav ul');

    menuIcon.addEventListener('click', () => {
        navLinks.style.display = navLinks.style.display === 'block' ? 'none' : 'block';
    });
});