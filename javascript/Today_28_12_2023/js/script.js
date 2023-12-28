function greet(name) {
    console.log("Hello, " + name + "!")
}

greet("Jonathan");


let multiply = function(x, y) {
    return x * y;
}

let result = multiply(5, 10);
console.log("The final result is: " + result + ".")


let temperature = 25;

if (temperature > 30 ) {
    console.log("It is a Hot day!");
} else if (temperature > 20 ) {
    console.log("it's a pleasant day.!");
} else {
    console.log("It's a cold day" )
}


let day = "Monday";

switch (day) {
    case "Monday":
        console.log("It's the start of the week.!");
        break;
        case "Friday":
            console.log("TGIF");
            break;
        default:
            console.log("It's a regular day.!");
}

