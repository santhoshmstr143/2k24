const addBtn = document.getElementById('addBtn');
const taskList = document.getElementById('taskList');
const input = document.getElementById('taskInput');


addBtn.addEventListener('click', () => {
    const newTask = document.createElement('li');
    newTask.className = 'task-item';
    newTask.innerHTML = `
        <span>${input.value}</span>
        <button class="delete-btn">X</button>
    `;
    taskList.appendChild(newTask);
    input.value = '';
});

const deleteButtons = document.querySelectorAll('.delete-btn');

deleteButtons.forEach(btn => {
    btn.addEventListener('click', (e) => {
        // e.target is the button. parentElement is the <li>
        e.target.parentElement.remove();
    });
});