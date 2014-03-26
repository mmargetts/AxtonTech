void nitelite_ui(EthernetClient cl){ 
cl.println("  <!DOCTYPE html> ");
cl.println("  <html>");
cl.println("      <head>");
cl.println("          <title>AxtonTech Illumnate the Night</title>");
cl.println("          <script>");
cl.println("        			_manualOff1 ='';");
cl.println("        			_button11   ='';");
cl.println("        			_button21   ='';");
cl.println("        			_button31   ='';");
cl.println("        			_dayNight1  ='';");
cl.println("");
cl.println("        			_manualOff2 ='';");
cl.println("        			_button12   ='';");
cl.println("        			_button22   ='';");
cl.println("        			_button32   ='';");
cl.println("        			_dayNight2='';");
cl.println("");
cl.println("        			_manualOff3 ='';");
cl.println("        			_button13   ='';");
cl.println("        			_button23   ='';");
cl.println("        			_button33   ='';");
cl.println("        			_dayNight3='';");
cl.println("");
cl.println("            function XMLToString(oXML) {   ");
cl.println("                if (window.ActiveXObject) {     ");
cl.println("                    return oXML.xml;  //if IE ");
cl.println("                } else {     ");
cl.println("                    return (new XMLSerializer()).serializeToString(oXML);   ");
cl.println("                } ");
cl.println("            }");
cl.println("        		function GetArduinoIO()");
cl.println("        		{");
cl.println("        			nocache = '&nocache=' + Math.random() * 1000000;");

cl.println("      			var request = new XMLHttpRequest();");
cl.println("      			request.onreadystatechange = function()");
cl.println("      			{");


cl.println("      				if (this.readyState == 4) {");
cl.println("      					if(this.status == 200) {");
cl.println("      						if (this.responseXML != null) {");
if(digitalRead(io_jumper_illuminator1)==0 || digitalRead(io_jumper_illuminator2) == 0 || digitalRead(io_jumper_illuminator3) == 0 ){
  cl.println("                                                            if (this.responseXML.getElementsByTagName('buttonStatus11')[0].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm1.button11.checked = true;");
  cl.println("								  document.illuminatorForm1.button21.checked = false;");
  cl.println("								  document.illuminatorForm1.button21.checked = false;");
  cl.println("							        } else { document.illuminatorForm1.button11.checked = false;}");

  cl.println("                                                            if (this.responseXML.getElementsByTagName('buttonStatus21')[0].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm1.button11.checked = false;");
  cl.println("								  document.illuminatorForm1.button21.checked = true;");
  cl.println("								  document.illuminatorForm1.button31.checked = false;");
  cl.println("							        } else { document.illuminatorForm1.button21.checked = false;}");

  cl.println("                                                            if (this.responseXML.getElementsByTagName('buttonStatus31')[0].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm1.button11.checked = false;");
  cl.println("								  document.illuminatorForm1.button21.checked = false;");
  cl.println("								  document.illuminatorForm1.button31.checked = true;");
  cl.println("							        } else { document.illuminatorForm1.button31.checked = false;}");

  cl.println("                                                            if (this.responseXML.getElementsByTagName('dayNightStatus')[0].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm1.dayNight1.checked  = true;");
//  cl.println("								  document.illuminatorForm1.button11.checked   = false;");
//  cl.println("								  document.illuminatorForm1.button21.checked   = false;");
//  cl.println("								  document.illuminatorForm1.button31.checked   = false;");
  cl.println("							        } else { document.illuminatorForm1.dayNight1.checked = false;}");

  cl.println("         							if (this.responseXML.getElementsByTagName('powerStatus')[0].childNodes[0].nodeValue === 'on') {");
  cl.println("      								document.getElementById('powerStatus1'     ).innerHTML = 'Illuminator Status on';");
  cl.println("                                                            }else{  document.getElementById('powerStatus1'     ).innerHTML = 'Illuminator Status off';}");
}
if(digitalRead(io_jumper_illuminator2) == 0 || digitalRead(io_jumper_illuminator3) == 0 ){

  cl.println("                                                            if (this.responseXML.getElementsByTagName('buttonStatus12')[0].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm2.button12.checked = true;");
  cl.println("								  document.illuminatorForm2.button22.checked = false;");
  cl.println("								  document.illuminatorForm2.button32.checked = false;");
  cl.println("							        } else { document.illuminatorForm2.button12.checked = false;}");

  cl.println("                                                            if (this.responseXML.getElementsByTagName('buttonStatus22')[0].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm2.button12.checked = false;");
  cl.println("								  document.illuminatorForm2.button22.checked = true;");
  cl.println("								  document.illuminatorForm2.button32.checked = false;");
  cl.println("							        } else { document.illuminatorForm2.button22.checked = false;}");

  cl.println("                                                            if (this.responseXML.getElementsByTagName('buttonStatus32')[0].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm2.button12.checked = false;");
  cl.println("								  document.illuminatorForm2.button22.checked = false;");
  cl.println("								  document.illuminatorForm2.button32.checked = true;");
  cl.println("							        } else { document.illuminatorForm2.button32.checked = false;}");

  cl.println("                                                            if (this.responseXML.getElementsByTagName('dayNightStatus')[1].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm2.dayNight2.checked = true;");
//  cl.println("								  document.illuminatorForm2.button12.checked = false;");
//  cl.println("								  document.illuminatorForm2.button22.checked = false;");
//  cl.println("								  document.illuminatorForm2.button32.checked = false;");
  cl.println("							        } else { document.illuminatorForm2.dayNight2.checked = false;}");

  cl.println("         							if (this.responseXML.getElementsByTagName('powerStatus')[1].childNodes[0].nodeValue === 'on') {");
  cl.println("      								document.getElementById('powerStatus2'     ).innerHTML = 'Illuminator Status on';");
  cl.println("                                                            }else{  document.getElementById('powerStatus2'     ).innerHTML = 'Illuminator Status off';}");

}

if(digitalRead(io_jumper_illuminator3) == 0 ){

  cl.println("                                                            if (this.responseXML.getElementsByTagName('buttonStatus13')[0].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm3.button13.checked = true;");
  cl.println("								  document.illuminatorForm3.button23.checked = false;");
  cl.println("							        } else { document.illuminatorForm3.button13.checked = false;}");

  cl.println("                                                            if (this.responseXML.getElementsByTagName('buttonStatus23')[0].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm3.button13.checked = false;");
  cl.println("								  document.illuminatorForm3.button23.checked = true;");
  cl.println("							        } else { document.illuminatorForm3.button23.checked = false;}");

  cl.println("                                                            if (this.responseXML.getElementsByTagName('dayNightStatus')[2].childNodes[0].nodeValue === 'on') {");
  cl.println("								  document.illuminatorForm3.dayNight3.checked = true;");
//  cl.println("								  document.illuminatorForm3.button13.checked = false;");
//  cl.println("								  document.illuminatorForm3.button23.checked = false;");
  cl.println("							        } else { document.illuminatorForm3.dayNight3.checked = false;}");

  cl.println("         							if (this.responseXML.getElementsByTagName('powerStatus')[2].childNodes[0].nodeValue === 'on') {");
  cl.println("      								document.getElementById('powerStatus3'     ).innerHTML = 'Illuminator Status on';");
  cl.println("                                                            }else{  document.getElementById('powerStatus3'     ).innerHTML = 'Illuminator Status off';}");

}

cl.println("                                                    }");
cl.println("                                            }");
cl.println("                                     }");

cl.println("                            }");
cl.println("        			request.open('GET', 'ajax_inputs' + _manualOff1 + _manualOff2 + _manualOff3 + _dayNight1 + _dayNight2 + _dayNight3 + _button11 + _button21 + _button31 + _button12 + _button22 + _button32 + _button13 + _button23 + _button33 + nocache, true);");
cl.println("        			request.send(null);");
cl.println("        			setTimeout('GetArduinoIO()', 1000);");

cl.println("        			_manualOff1 ='';");
cl.println("        			_button11   ='';");
cl.println("        			_button21   ='';");
cl.println("        			_button31   ='';");
cl.println("        			_dayNight1  ='';");
cl.println("");
cl.println("        			_manualOff2 ='';");
cl.println("        			_button12   ='';");
cl.println("        			_button22   ='';");
cl.println("        			_button32   ='';");
cl.println("        			_dayNight2='';");
cl.println("");
cl.println("        			_manualOff3 ='';");
cl.println("        			_button13   ='';");
cl.println("        			_button23   ='';");
cl.println("        			_button33   ='';");
cl.println("        			_dayNight3='';");
cl.println("");
cl.println("        		}");
cl.println("        ");
cl.println("    ");
cl.println("    ");
cl.println("        		function GetButton11()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm1.button11.checked === true && document.illuminatorForm1.dayNight1.checked === false){_button11='&button11=1';}else{_button11='&button11=0';}");
cl.println("        		}");
cl.println("        		function GetButton21()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm1.button21.checked === true && document.illuminatorForm1.dayNight1.checked === false){_button21='&button21=1';}else{_button21='&button21=0';}");
cl.println("        		}");
cl.println("        		function GetButton31()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm1.button31.checked === true && document.illuminatorForm1.dayNight1.checked === false){_button31='&button31=1';}else{_button31='&button31=0';}");
cl.println("        		}");
cl.println("        		function GetButtonDayNight1()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm1.dayNight1.checked === true){_dayNight1='&dayNight1=1';}else{_dayNight1='&dayNight1=0';}");
cl.println("        		}");
cl.println("");
cl.println("        		function GetButton12()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm2.button12.checked === true && document.illuminatorForm2.dayNight2.checked === false){_button12='&button12=1';}else{_button12='&button12=0';}");
cl.println("        		}");
cl.println("        		function GetButton22()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm2.button22.checked === true && document.illuminatorForm2.dayNight2.checked === false){_button22='&button22=1';}else{_button22='&button22=0';}");
cl.println("        		}");
cl.println("        		function GetButton32()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm2.button32.checked === true && document.illuminatorForm2.dayNight2.checked === false){_button32='&button32=1';}else{_button32='&button32=0';}");
cl.println("        		}");
cl.println("        		function GetButtonDayNight2()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm2.dayNight2.checked === true){_dayNight2='&dayNight2=1';}else{_dayNight2='&dayNight2=0';}");
cl.println("        		}");
cl.println("");
cl.println("        		function GetButton13()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm3.button13.checked === true && document.illuminatorForm3.dayNight3.checked === false){_button13='&button13=1'; }else{_button13='&button13=0';}");
cl.println("        		}");
cl.println("        		function GetButton23()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm3.button23.checked === true && document.illuminatorForm3.dayNight3.checked === false){_button23='&button23=1';}else{_button23='&button23=0';}");
cl.println("        		}");
cl.println("        		function GetButtonDayNight3()");
cl.println("        		{");
cl.println("                           if (document.illuminatorForm3.dayNight3.checked === true){_dayNight3='&dayNight3=1';}else{_dayNight3='&dayNight3=0';}");
cl.println("        		}");
cl.println("        		");
cl.println("        		");
cl.println("  	      </script>");
cl.println("");
cl.println("  	<style>");
cl.println("  		.IO_box {");
cl.println("  			float  : left;");
cl.println("  			margin : 0 10px 25px 0;");
cl.println("  			border : 1px solid #73bc43;");
cl.println("  			padding: 0 5px 0 5px;");
cl.println("  			width  : 180px;");
cl.println("  		}");
cl.println("  		.h1 {");
cl.println("  			font-family: arial, sans-serif;font-size: 120%; ");
cl.println("  			color: #73bc43;");
cl.println("  			margin: 0 0 10px 0;");
cl.println("  		}");
cl.println("  		.h2 {");
cl.println("  			font-family: arial, sans-serif;font-size: 85%;");
cl.println("  			color: #73bc43;");
cl.println("  			margin: 5px 0 5px 0;");
cl.println("  		}");
cl.println("  		p, form, button {");
cl.println("  			font-size: 85%;");
cl.println("  			color: #252525;");
cl.println("  			");
cl.println("  			");
cl.println("  		}");
cl.println("  		.small_text {");
cl.println("  			font-size: 70%;");
cl.println("  			color: #737373;");
cl.println("  		}");
cl.println("            .powerRed{");
cl.println("  	            background-color:red;");
cl.println("  	            color:white;");
cl.println("  	        }");
cl.println("            .powerGreen{");
cl.println("  	            background-color:green;");
cl.println("  	            color:white;");
cl.println("  	        }");
cl.println("  	</style>");
cl.println("      </head>");
cl.println("");
cl.println("<img style='align:right' src='data:image/png;base64,");
  for (int i=0;i<21;i++){
    cl.write(logo_raw[i]);
  }
cl.println("'> ");                     
cl.println("<p>");
cl.println("      <body onload='GetArduinoIO()'>");
if(digitalRead(io_jumper_illuminator1)==0 || digitalRead(io_jumper_illuminator2) == 0 || digitalRead(io_jumper_illuminator3) == 0 ){
cl.println("  		<div class='IO_box' >");
cl.println("");
  cl.println("          <span class='h1'>XLR</span>");
  cl.println("          <br/><br/>");
  cl.println("<form id='illuminator1' name='illuminatorForm1'>");
  cl.println("  				<input type='checkbox'  class='button11'     id='button11'    name='button11'      onclick='GetButton11()'        /> Low      <br />");
  cl.println("  				<input type='checkbox'  class='button21'     id='button21'    name='button21'      onclick='GetButton21()'        /> Medium   <br />");
  cl.println("  				<input type='checkbox'  class='button31'     id='button31'    name='button31'      onclick='GetButton31()'        /> High     <br />");
  cl.println("<hr>");
  cl.println("  				<input type='checkbox'  class='dayNight'  id='dayNight1'   name='dayNight1'   onclick='GetButtonDayNight1()'   /> D/N Switch Enable<br />");
  cl.println("  				<class='powerStatus' id='powerStatus1'                                             />Illuminator Status off<br /><br/>");
  cl.println("  		</div>");
  cl.println("</form>");
}
cl.println("");
if(digitalRead(io_jumper_illuminator2) == 0 || digitalRead(io_jumper_illuminator3) == 0){
  cl.println("  		<div class='IO_box' >");
  cl.println("");
  cl.println("          <span class='h1'>Zoom</span>");
  cl.println("          <br/><br/>");
  cl.println("<form id='illuminator2' name='illuminatorForm2'>");
  cl.println("  				<input type='checkbox'  class='button12'     id='button12'     name='button12'     onclick='GetButton12()'   />  Narrow <br />");
  cl.println("  				<input type='checkbox'  class='button22'     id='button22'     name='button22'     onclick='GetButton22()'   />  Medium <br />");
  cl.println("  				<input type='checkbox'  class='button32'     id='button32'     name='button32'     onclick='GetButton32()'   />  Wide   <br />");
  cl.println("<hr>");
  cl.println("  				<input type='checkbox'  class='dayNight'  id='dayNight2'    name='dayNight2'     onclick='GetButtonDayNight2()'   /> D/N Switch Enable<br />");
  cl.println("  				<class='powerStatus' id='powerStatus2'                                                      />Illuminator Status off<br /><br/>");
  cl.println("  		</div>");
  cl.println("</form>");
}
cl.println("");
if(digitalRead(io_jumper_illuminator3)==0){
  cl.println("  		<div class='IO_box' >");
  cl.println("");
  cl.println("          <span class='h1'>Hybrid</span>");
  cl.println("          <br/><br/>");
  cl.println("<form id='illuminator3' name='illuminatorForm3'>");
  cl.println("  				<input type='checkbox'  class='button13'    id='button13'    name='button13'     onclick='GetButton13()'   /> IR<br />");
  cl.println("  				<input type='checkbox'  class='button23'    id='button23'    name='button23'     onclick='GetButton23()'   /> White<br />");
  cl.println("<hr>");
  cl.println("  				<input type='checkbox'  class='dayNight'    id='dayNight3'    name='dayNight3' onclick='GetButtonDayNight3()'  /> D/N Switch Enable<br />");
  cl.println("  				<class='powerStatus' id='powerStatus3'                                                     />Illuminator Status off<br /><br/>");
  cl.println("  		</div>");
  cl.println("</form>");
}
cl.println("           ");
cl.println("      </body>");
cl.println("  </html>");
}

