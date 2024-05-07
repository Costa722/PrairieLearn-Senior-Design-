var onePort = "A";
var twoPort = "C";
var randNumArr = [1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1];



//get canvas element and draw rectangle on it

function arrowDirection(upOrDown, ctx, fromx, fromy, tox, toy) {
    if (upOrDown === 1)
        drawArrow(ctx, fromx, fromy, tox, toy, 2, "#000000");
    else
        drawArrow(ctx, fromx, toy, tox, fromy, 2, "#000000");
}

function drawArrow(ctx, fromx, fromy, tox, toy, arrowWidth, color) {
    //variables to be used when creating the arrow
    var headlen = 10;
    var angle = Math.atan2(toy - fromy, tox - fromx);

    ctx.save();
    ctx.strokeStyle = color;

    //starting path of the arrow from the start square to the end square
    //and drawing the stroke
    ctx.beginPath();
    ctx.moveTo(fromx, fromy);
    ctx.lineTo(tox, toy);
    ctx.lineWidth = arrowWidth;
    ctx.stroke();

    //starting a new path from the head of the arrow to one of the sides of
    //the point
    ctx.beginPath();
    ctx.moveTo(tox, toy);
    ctx.lineTo(tox - headlen * Math.cos(angle - Math.PI / 7),
        toy - headlen * Math.sin(angle - Math.PI / 7));

    //path from the side point of the arrow, to the other side point
    ctx.lineTo(tox - headlen * Math.cos(angle + Math.PI / 7),
        toy - headlen * Math.sin(angle + Math.PI / 7));

    //path from the side point back to the tip of the arrow, and then
    //again to the opposite side point
    ctx.lineTo(tox, toy);
    ctx.lineTo(tox - headlen * Math.cos(angle - Math.PI / 7),
        toy - headlen * Math.sin(angle - Math.PI / 7));

    //draws the paths created above
    ctx.stroke();
    ctx.restore();
}

function drawCircle(ctx, x, y, radius) {
    ctx.beginPath();
    ctx.arc(x, y, radius, 0, 2 * Math.PI);
    ctx.stroke();
}

//draw the port letters on the canvas
function drawPorts(ctx) {
    ctx.font = "30px Arial";
    ctx.fillText("Port " + onePort, 120, 250)

    ctx.fillText("Port " + twoPort, 360, 250)
}



var canvas = document.getElementById("myCanvas");
var ctx = canvas.getContext("2d");
ctx.fillStyle = "#000000";

rectWidth = 500;
rectHeight = 270;
var rectX = canvas.width / 2 - rectWidth / 2;
var rectY = canvas.height / 2 - rectHeight / 2;

ctx.strokeRect(rectX, rectY - 20, rectWidth, rectHeight);

var txtX = canvas.width / 2 - rectX - 110;
var txtY = canvas.height / 2 - rectY / 2;


ctx.font = "25px Arial";
ctx.fillText("TM4C123 Microcontroller", txtX, txtY);

//place the number 7 through 0 twice equal distance at the bottom of the rectangle
ctx.font = "12px Arial";

var space = 20
var xSpacesArr = [];
var ySpacesArr = rectY + rectHeight;
for (var i = 0; i < 2; i++) {
    for (var j = 7; j > -1; j--) {
        xSpacesArr.push(rectX + space + 3);
        ctx.fillText(j, rectX + space, rectY + rectHeight - 25);
        space += 30
    }

}

//create 16 random numbers and add to array
// var randNumArr = [];
// for (var i = 0; i < 16; i++) {
//     randNumArr.push(Math.floor(Math.random() * 2));
// }

// //make sure there are at least 2 0's and 2 1's in the first 8 numbers and last 8 numbers
// var count = 0;
// for (var i = 0; i < 8; i++) {
//     if (randNumArr[i] === 0)
//         count++;
// }

// while (count < 2) {
//     //randomly replace 1's with 0's until there are 2 0's
//     random = Math.floor(Math.random() * 8);
//     if (randNumArr[random] === 1) {
//         randNumArr[random] = 0;
//         count++;
//     }
// }

// var count = 0;
// for (var i = 8; i < 16; i++) {
//     if (randNumArr[i] === 0)
//         count++;
// }
// while (count < 2) {
//     //random 8 through 15
//     random = Math.floor(Math.random() * 8) + 8;
//     if (randNumArr[random] === 1) {
//         randNumArr[random] = 0;
//         count++;
//     }
// }


// draw the arrows the right direction based on the numbers in the array 
for (var i = 0; i < xSpacesArr.length; i++) {
    arrowDirection(randNumArr[i], ctx, xSpacesArr[i], ySpacesArr - 19, xSpacesArr[i], ySpacesArr + 20)
}


b0b1 = []
b2b3 = []
l0l1 = []
l2l3 = []

//randomly choose 2 1's indexes and 2 0's indexes from first 8 numbers
while (b0b1.length < 2) {
    var random = Math.floor(Math.random() * 8);
    if (randNumArr[random] === 0) {
        //if the index is not already in the array, add it
        if (b0b1.indexOf(random) === -1)
            b0b1.push(random);
    }
}

while (b2b3.length < 2) {
    var random = Math.floor(Math.random() * 8) + 8;
    if (randNumArr[random] === 0) {
        //if the index is not already in the array, add it
        if (b2b3.indexOf(random) === -1)
            b2b3.push(random);
    }
}

while (l0l1.length < 2) {
    var random = Math.floor(Math.random() * 8);
    if (randNumArr[random] === 1) {
        //if the index is not already in the array, add it
        if (l0l1.indexOf(random) === -1)
            l0l1.push(random);
    }
}

while (l2l3.length < 2) {
    var random = Math.floor(Math.random() * 8) + 8;
    if (randNumArr[random] === 1) {
        //if the index is not already in the array, add it
        if (l2l3.indexOf(random) === -1)
            l2l3.push(random);
    }
}

//draw the circles containing the letters B0, B1, B2, B3, L0, L1, L2, L3
for (var i = 0; i < b0b1.length; i++) {
    drawCircle(ctx, xSpacesArr[b0b1[i]], ySpacesArr + 33, 14);
    if (i === 0)
        ctx.fillText("B0", xSpacesArr[b0b1[i]] - 8, ySpacesArr + 38);
    else
        ctx.fillText("B1", xSpacesArr[b0b1[i]] - 8, ySpacesArr + 38);
}

for (var i = 0; i < b2b3.length; i++) {
    drawCircle(ctx, xSpacesArr[b2b3[i]], ySpacesArr + 33, 14);
    if (i === 0)
        ctx.fillText("B2", xSpacesArr[b2b3[i]] - 8, ySpacesArr + 38);
    else
        ctx.fillText("B3", xSpacesArr[b2b3[i]] - 8, ySpacesArr + 38);
}

for (var i = 0; i < l0l1.length; i++) {
    drawCircle(ctx, xSpacesArr[l0l1[i]], ySpacesArr + 33, 14);
    if (i === 0)
        ctx.fillText("L0", xSpacesArr[l0l1[i]] - 8, ySpacesArr + 38);
    else
        ctx.fillText("L1", xSpacesArr[l0l1[i]] - 8, ySpacesArr + 38);
}

for (var i = 0; i < l2l3.length; i++) {
    drawCircle(ctx, xSpacesArr[l2l3[i]], ySpacesArr + 33, 14);
    if (i === 0)
        ctx.fillText("L2", xSpacesArr[l2l3[i]] - 8, ySpacesArr + 38);
    else
        ctx.fillText("L3", xSpacesArr[l2l3[i]] - 8, ySpacesArr + 38);
}

drawPorts(ctx)