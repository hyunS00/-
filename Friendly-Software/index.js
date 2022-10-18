let clickNav = document.querySelector(".nav");
let clickNavItem = document.querySelector(".link");
const $product = document.getElementById("productNav");
const $booth = document.getElementById("boothNav");
const $contact = document.getElementById("contactNav");
const removeActive = () => {
  if (!$product.classList.contains(".active")) {
    $product.classList.remove("active");
  }
  if (!$booth.classList.contains(".active")) {
    $booth.classList.remove("active");
  }
  if (!$contact.classList.contains(".active")) {
    $contact.classList.remove("active");
  }
};
clickNav.addEventListener("click", (e) => {
  removeActive();
  console.log("클릭", e.target);
  e.target.classList.add("active");
  clickNavItem = e.target;
});

const scrollFunc = () => {
  let scrollHeight = scrollY + window.innerHeight;
  let documentHeight = document.body.scrollHeight;

  // console.log("scrollHeight:" + scrollHeight);
  // console.log("yoffset:" + scrollY);

  // console.log("documentHeight" + documentHeight);
  if (!$booth.classList.contains(".active")) {
    $booth.classList.remove("active");
  }
  if (!$contact.classList.contains(".active")) {
    $contact.classList.remove("active");
  }
  if (scrollY >= 10 && !$product.classList.contains("active")) {
    $product.classList.add("active");
  }
};

const scrollLimit = () => {
  let scrollWidth = scrollX + window.innerHeight;
  let documentWidth = document.body.scrollWidth;
  console.log("scrollWidth:" + scrollWidth);
  console.log("scrollX:" + scrollX);
  console.log("documentWidth" + documentWidth);
  if (scrollWidth > 0) {
    window.scrollTo({ left: 0, behavior: "instant" });
  }
};

const targets = document.querySelectorAll(".fade-class");
const options = { root: null, threshold: 0.1, rootMargin: "-0px" };
const observer = new IntersectionObserver(function (entries, observer) {
  entries.forEach((entry) => {
    const container = entry.target;
    if (entry.isIntersecting) {
      container.classList.add("fade-in");
    } else {
      container.classList.remove("fade-in");
    }
  });
}, options);

targets.forEach((target) => {
  observer.observe(target);
});

window.addEventListener("scroll", scrollFunc);
window.addEventListener("scroll", scrollLimit);
