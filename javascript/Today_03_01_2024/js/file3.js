// Chaining Promises

function fetchUserData() {
    return new Promise(function(resolve, reject) {
        setTimeout(function() {
            let success = true;
            if (success) {
                resolve("User data Fetch Successfully.!");
            } else {
                reject("Error Fetching Data");
            }
        }, 2000);
    });
}

// Chaining Promises.
fetchUserData()
    .then(function(userData) {
        console.log(userData);
        return processUserData(userData);
    })
    .then(function(processUserData){
        console.log(processUserData);
    })
    .catch(function(error) {
        console.log(error);
    });