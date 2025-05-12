const nameForm = document.querySelector('#review-form');
const nameInput = document.querySelector('#name-input');
const reviewInput = document.querySelector('#review-input');
const ratingInputs = document.querySelectorAll('input[name="rating"]');

document.addEventListener('submit', (event) => {
    event.preventDefault(); // prevent the default form submission behavior

    const name = nameInput.value; // get the value of the name input field
    let review = reviewInput.value;
    let rating; // initialize a variable to store the rating value
    
    if(name === ""){
        alert("Enter Name");
        return;
    }
    if(review === ""){
        review = "(no opinion)";
    }
    // loop through the rating radio buttons to find the checked one
    ratingInputs.forEach((input) => {
        if (input.checked) {
            rating = input.value;
            input.checked=false;
        }
    });
    if(rating === undefined)
    {
        alert("Enter Rating");
        return;
    }

    // create a new row in the table with the name and rating values
    const table = document.querySelector('#results-table');
    const newRow = table.insertRow();

    const nameCell = newRow.insertCell();
    nameCell.textContent = name;
    nameCell.classList.add('name_td');
    const ratingCell = newRow.insertCell();
    ratingCell.textContent = rating;
    ratingCell.classList.add('name_td');
    const reviewCell = newRow.insertCell();
    reviewCell.textContent = review;
    reviewCell.classList.add('name_td');
    nameInput.value="";
    reviewInput.value="";
});

const countdownElement = document.querySelector('#countdown');

function updateCountdown() {
    const june30 = new Date('2023-06-30T00:00:00Z'); // create a Date object for June 30 00:00 IST
    const now = new Date(); // create a Date object for the current time
    const timeRemaining = june30 - now; // calculate the difference in milliseconds

    // convert milliseconds to days, hours, minutes, and seconds
    const days = Math.floor(timeRemaining / (1000 * 60 * 60 * 24));
    const hours = Math.floor((timeRemaining % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    const minutes = Math.floor((timeRemaining % (1000 * 60 * 60)) / (1000 * 60));
    const seconds = Math.floor((timeRemaining % (1000 * 60)) / 1000);

    // construct the countdown timer string
    const countdownString = `${days} days, ${hours} hrs, ${minutes} min, ${seconds} sec`;

    // update the HTML element with the countdown timer
    countdownElement.textContent = countdownString;
}

// call the updateCountdown function every second to update the timer
setInterval(updateCountdown, 1000);