function compile() {
     $.ajax({
          type: 'POST',
          url: 'php/compile.php',
          data: {
               'input': document.getElementById("input").value,
          },
          success: function(input) {
               console.log(input);
               var data = JSON.parse(input);
               console.log(data);
               document.getElementById("output-asm").value = data.asm;
               document.getElementById("output-terminal").value = data.terminal;
          }
     });
}
