const loadBtn = document.getElementById('loadBtn');
const userIdInput = document.getElementById('userIdInput');
const userCard = document.getElementById('userCard');
const userName = document.getElementById('userName');
const userEmail = document.getElementById('userEmail');

// THE BUGGY FUNCTION
// - No Error Handling
// - No Loading State
// - No "Not Found" check

loadBtn.addEventListener('click', async () => {
    const userId = userIdInput.value;
    
    // 1. Fetch data
    const response = await fetch(`https://jsonplaceholder.typicode.com/users/${userId}`);
    
    // 2. Parse JSON
    const data = await response.json();
    
    // 3. Update UI
    // If user is 404, 'data' is empty, but code tries to read data.name -> Undefined!
    userCard.classList.remove('hidden');
    userName.textContent = data.name;
    userEmail.textContent = data.email;
});
