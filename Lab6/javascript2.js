/* This Javascript file will be used to take the inputs from the three input fields in practice2.html, and send those values to the corresponding css properties in the style2.css file, using changeFontColor(). */

function changeFontColor() {
    // Get the input values
    const red = document.getElementById('red').value;
    const green = document.getElementById('green').value;
    const blue = document.getElementById('blue').value;

    // Create the RGB color string
    const textColor = `rgb(${255 - red}, ${255 - green}, ${255 - blue})`; // Invert the color for text

    // Change the text color and border of all p elements
    const paragraphs = document.querySelectorAll('p');
    paragraphs.forEach(p => {
        p.style.color = textColor;
        p.style.borderColor = textColor; // Change border color to match text color
    });
}