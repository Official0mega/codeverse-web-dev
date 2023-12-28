function greet(name) {
    console.log("Hello, " + name + "!")
}

greet("Arjen Ruben");


function square(number) {
    return number ** number;
}

let result = square(3);
console.log(result);

let car = {
    brand: "Benz",
    model: "fervent",
    year: 2024,
    start: function() {
        console.log("The Engine Started Successfully!")
    }
};


console.log(car.model);
car.start();




