description('Test for keyboard operations for &lt;input type=number>');
var parent = document.createElement('div');
document.body.appendChild(parent);
parent.innerHTML = '<input type=number id=number>';

var input = document.getElementById('number');
input.focus();
debug('Inserting "ab123cd":');
document.execCommand('InsertText', false, 'ab123cd');
shouldBe('input.value', '"123"');

debug('Press the up arrow key:');
eventSender.keyDown('upArrow');
shouldBe('input.value', '"124"');

debug('Press the down arrow key:');
eventSender.keyDown('downArrow');
shouldBe('input.value', '"123"');

var successfullyParsed = true;
