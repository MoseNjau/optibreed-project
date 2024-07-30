document.addEventListener("DOMContentLoaded", function() {
  // Get all buttons and tab content divs
  const buttons = document.querySelectorAll(".nav-link");
  const tabContents = document.querySelectorAll(".tab-pane");
  const aboutSection = document.getElementById("about");
  const whoWeAreTab = document.getElementById("pills-who-we-are-tab");
  const whoWeAreContent = document.getElementById("pills-who-we-are");

  // Function to remove active class from all buttons and hide all tab contents
  function resetTabs() {
    buttons.forEach(button => {
      button.classList.remove("active");
    });
    tabContents.forEach(content => {
      content.classList.remove("show", "active");
    });
  }

  // Add click event listener to each button
  buttons.forEach(button => {
    button.addEventListener("click", function() {
      // Reset all tabs
      resetTabs();
      
      // Add active class to clicked button
      this.classList.add("active");
      
      // Show the corresponding tab content
      const target = document.querySelector(this.dataset.bsTarget);
      target.classList.add("show", "active");
    });
  });

  // Intersection Observer to observe when the about section is in view
  const observer = new IntersectionObserver(entries => {
    entries.forEach(entry => {
      if (entry.isIntersecting) {
        // Reset all tabs
        resetTabs();
        
        // Add active class to "Who We Are" button and content
        whoWeAreTab.classList.add("active");
        whoWeAreContent.classList.add("show", "active");
      }
    });
  }, {
    threshold: 0.5 // Adjust this value as needed
  });

  // Start observing the about section
  observer.observe(aboutSection);

  // Automatically click the "Who We Are" tab on page load
  whoWeAreTab.click();
});
