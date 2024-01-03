// Async & Await operations

function fetchData() {
    return new Promise(function(resolve, reject) {
        setTimeout(function() {
            resolve("Fetched Data was Successfully.!");
        }, 2000);
    });
}

async function fetchDataAndProcess() {
    try {
        let data = await fetchData();
        console.log("Data was Received: " + data)
    } catch (error) {
        console.error("Error: ", error);
    }
}

// USing Async and Await
fetchDataAndProcess();