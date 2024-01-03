// Callback operations examples.
function fetchData(Callback) {
    setTimeout(function () {
        let data = "Fetch data!";
        Callback(data);
    }, 2000);
}

fetchData(function(result) {
    console.log(result);
})