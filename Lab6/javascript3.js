//  In this practice, the user will allow the user to type in a password in two seperate input boxes. If the two passwords don't match, then we will tell the user the passwords don't match. If they do match, we will tell the user the passwords match.

function verifyPassword() {
    // Get the password values
    const password1 = document.getElementById('password1').value;
    const password2 = document.getElementById('password2').value;

    // Check if the passwords match
    // p element to display the message has id="message"

    const messageElement = document.getElementById('message');
    if (password1 === password2) {
        messageElement.textContent = 'Passwords match!';
        messageElement.style.color = 'green';
    } else {
        messageElement.textContent = 'Passwords do not match!';
        messageElement.style.color = 'red';
    }
}
