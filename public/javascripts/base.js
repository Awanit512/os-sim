$(document).ready(function () {

	// to load the time
	setInterval(function() {
		var time = new Date();
		var	hours = time.getHours();
		var	minutes = time.getMinutes();

		if(minutes<10) 
		{
			minutes = "0" + minutes;
		}

		if(hours>=12) 
		{
			hours = hours-12;
            $('#time').text(hours + ':' + minutes + ' PM');
		}

		else 
		{
            $('#time').text(hours + ':' + minutes + ' AM');
		}

	},1000);
});

// to set height - jugaad
var height = $(window).height() - $('.top-navbar').height();
$('.side-navbar').height(2*height);

// set initially the file onclick as hidden
$("#side_bar").hide();

$(".desktop-overlay").hide();

$(".side-navbar button").click(function(){
	$(".desktop-overlay").fadeToggle('200');

	$(".side-navbar").toogleClass('opacity');
});
// toogle file click function
function openFile(){
	$('#side_bar').toggle(100);
}

$('#pgr').hover(function(){
	$("#viewer").css("visibility","visible");
	$('#viewer').text("Page replacement");
});

$('#pgr').mouseout(function(){
    $("#viewer").css("visibility","hidden");
});

$('#cpu').hover(function(){
    $("#viewer").css("visibility","visible");
    $('#viewer').text("CPU scheduling");
});

$('#cpu').mouseout(function(){
    $("#viewer").css("visibility","hidden");
});

$('#disk').hover(function(){
    $("#viewer").css("visibility","visible");
    $('#viewer').text("Disk scheduling");
});

$('#disk').mouseout(function(){
    $("#viewer").css("visibility","hidden");
});

$('#mem').hover(function(){
    $("#viewer").css("visibility","visible");
    $('#viewer').text("Memory allocation");
});

$('#mem').mouseout(function(){
    $("#viewer").css("visibility","hidden");
});

$('#file').hover(function(){
    $("#viewer").css("visibility","visible");
    $('#viewer').text("File allocation");
});

$('#file').mouseout(function(){
    $("#viewer").css("visibility","hidden");
});

$('#banker').hover(function(){
    $("#viewer").css("visibility","visible");
    $('#viewer').text("Deadlock and Banker");
});

$('#banker').mouseout(function(){
    $("#viewer").css("visibility","hidden");
});

$('#sync').hover(function(){
    $("#viewer").css("visibility","visible");
    $('#viewer').text("Process sync");
});

$('#sync').mouseout(function(){
    $("#viewer").css("visibility","hidden");
});