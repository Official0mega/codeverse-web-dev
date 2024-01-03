// Promises Operations.

function fetchData() {
    return new Promise(function(resolve, reject) {
        setTimeout(function() {
            let success = true;
            if (success) {
                resolve("Fetched data!");
            } else {
                reject("Error fetching data!");
            }
        }, 2000);
    });
}


fetchData()
    .then(function(result) {
        console.log(result);
    })
    .catch(function(error) {
        console.log(error);
    })