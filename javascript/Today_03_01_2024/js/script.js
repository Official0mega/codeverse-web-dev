// Basic event handling

let myButton = document.getElementById("myButton");

myButton.addEventListener("click", function(event) {
    alert("Button Click at cordinates: " + event.clientX + ", " + event.clientY);
});