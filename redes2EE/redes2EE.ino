//BIBLIOTECAS A SEREM IMPORTADAS PARA UTILIZAÇÃO DO  SHIELD ETHERNET

#include <SPI.h>
#include <Ethernet.h>

int ledPortao = 4;
int ledLuz = 5;
int ledAr = 7;

//REDE ROTEADOR TPLINK
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //endereço do mac
byte ip[] = { 192, 168, 0, 104};                      // indereço de ip armazenado em um array [ESSE ENDEREÇO É O QUE VAI SER USADO PARA ACESSAR A APLICAÇÃO WEB NO BROWSER]
byte gateway[] = { 192, 168, 0, 1};                   // gatway padrão
byte subrede[] = { 255, 255, 255, 0 };                  //mascara de subrede
EthernetServer server(80);                             //Porta a ser usada     

//cria uma string onde vai ser armazenado [no nosso caso, a entrada do cliente, ou seja, os botoes do codigo html]
String readString;

void setup() {
 //Abre a comunicação serial
  Serial.begin(9600);
   while (!Serial) {
    ; // Espera por uma coneção
  }

  // seta o pino 4, 5, 6 como saida de 5v para o led
  pinMode(ledPortao, OUTPUT);
  pinMode(ledLuz, OUTPUT);
  pinMode(ledAr, OUTPUT);

  // Começa a conexão Ethernet / servidor
  Ethernet.begin(mac, ip, gateway, subrede);
  server.begin();
  Serial.print("Servidor iniciado: ");
  
  // printa o endereço de IP apenas como uma forma de verificação
  Serial.println(Ethernet.localIP());
}


void loop() {
  
  // Cria uma conexão com o cliente
    EthernetClient cliente = server.available();
  if (cliente) {
    while (cliente.connected()) {   
      if (cliente.available()) {
        char c = cliente.read();
     
        //Lê char por char - HTTP request 
        if (readString.length() < 100) {
          //Armazena os character em uma String
          readString += c;
          //Serial.print(c);
         }

        
         if (c == '\n') {          
           Serial.println(readString); //print para debuging
     
           cliente.println("HTTP/1.1 200 OK"); 
           cliente.println("Content-Type: text/html");
           cliente.println();     

           //INICIO DO CÓDIGO HTML
           
           cliente.println("<HTML>");
           cliente.println("<HEAD>");
           cliente.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
           cliente.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
           //cliente.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
           cliente.println("<TITLE>PROJETO REDES 2EE</TITLE>");
           cliente.println("<meta charset=\"utf-8\">");
           cliente.println("</HEAD>");
           cliente.println("<BODY>");
           cliente.println("<H1>PROJETO 2EE - REDES E COMPUTADORES</H1>");
           cliente.println("<hr />");
           cliente.println("<br />");  
           cliente.println("<H2>CRIANDO SERVERWEB USANDO ARDUINO E SHILD ETHERNET</H2>");
           
           
           cliente.println("<br />");  
           cliente.println("<h1>DISPOSITIVOS DISPONÍVEIS</h1>");
           
          
          
           //INICIO DO CÓDIGO CSS - pagina !
           
           cliente.println("<style type=\"text/css\">");
            
           cliente.println(" body{");
           cliente.println("margin:60px 0px; padding:0px;");
           cliente.println("text-align:center;");
           cliente.println("}");
           cliente.println("h1");
           cliente.println("{");
           cliente.println("text-align: center;");
           cliente.println("font-family:Arial, \"Trebuchet MS\", Helvetica, sans-serif;");
           cliente.println("}");
           cliente.println("h2");
           cliente.println("{");
           cliente.println("text-align: center;");
           cliente.println("font-family:Arial, \"Trebuchet MS\", Helvetica, sans-serif;");
           cliente.println("}");
           cliente.println("a");
           cliente.println("{");
           cliente.println("text-decoration:none;");
           cliente.println("width:75px;");
           cliente.println("height:50px;");
           cliente.println("border-color:black;");
           cliente.println("border-top:2px solid;");
           cliente.println("border-bottom:2px solid;");
           cliente.println("border-right:2px solid;");
           cliente.println("border-left:2px solid;");
           cliente.println("border-radius:10px 10px 10px;");
           cliente.println("-o-border-radius:10px 10px 10px;");
           cliente.println("-webkit-border-radius:10px 10px 10px;");
           cliente.println("font-family:\"Trebuchet MS\",Arial, Helvetica, sans-serif;");
           cliente.println("-moz-border-radius:10px 10px 10px;");
           cliente.println("background-color:#293F5E;");
           cliente.println("padding:8px;");
           cliente.println("text-align:center;");
           cliente.println("}");
           cliente.println("a:link {color:white;}      /* unvisited link */");
           cliente.println("a:visited {color:white;}  /* visited link */");
           cliente.println("a:hover {color:white;}  /* mouse over link */");
           cliente.println("a:active {color:white;}  /* selected link */");
            
           //final do css relacionado aos botões           
           cliente.println("body {");
           cliente.println("font-family: 'Open Sans', sans-serif;");
           cliente.println("font-weight: 300;");
           cliente.println("line-height: 1.42em;");
           cliente.println("color:#A7A1AE;");
           cliente.println("background-color:#1F2739;");
           cliente.println("}");
         
           cliente.println("h1 {");
           cliente.println("font-size:3em; ");
           cliente.println("font-weight: 300;");
           cliente.println("line-height:1em;");
           cliente.println("text-align: center;");
           cliente.println("color: #4DC3FA;");
           cliente.println("}");
          
           cliente.println("h2{");
           cliente.println("font-size:1em; ");
           cliente.println("font-weight: 300;");
           cliente.println("text-align: center;");
           cliente.println("display: block;");
           cliente.println("line-height:1em;");
           cliente.println("padding-bottom: 2em;");
           cliente.println("color: #FB667A;");
           cliente.println("}");
           cliente.println("h2 a {");
           cliente.println("font-weight: 700;");
           cliente.println("text-transform: uppercase;");
           cliente.println("color: #FB667A;");
           cliente.println("text-decoration: none;");
           cliente.println("}");
           cliente.println(".blue { color: #185875; }");
           cliente.println(".yellow { color: #FFF842; }");
           cliente.println(".container th h1 {");
           cliente.println("font-weight: bold;");
           cliente.println("font-size: 1em;");
           cliente.println("text-align: left;");
           cliente.println("color: #185875;");
           cliente.println("}");
          
           cliente.println(".container td {");
           cliente.println("font-weight: normal;");
           cliente.println("font-size: 1em;");
           cliente.println("-webkit-box-shadow: 0 2px 2px -2px #0E1119;");
           cliente.println("-moz-box-shadow: 0 2px 2px -2px #0E1119;");
           cliente.println("box-shadow: 0 2px 2px -2px #0E1119;");
           cliente.println("}");
           cliente.println(".container {");
           cliente.println("text-align: left;");
           cliente.println("overflow: hidden;");
           cliente.println("width: 80%;");
           cliente.println("margin: 0 auto;");
           cliente.println("display: table;");
           cliente.println("padding: 0 0 8em 0;");
           cliente.println("}");
           cliente.println(".container td, .container th {");
           cliente.println("padding-bottom: 2%;");
           cliente.println("padding-top: 2%;");
           cliente.println("padding-left:2%;  ");
           cliente.println("}");
           cliente.println("/* Background-color of the odd rows */");
           cliente.println(".container tr:nth-child(odd) {");
           cliente.println("background-color: #323C50;");
           cliente.println("}");
          
           cliente.println(" .container tr:nth-child(even) {");
           cliente.println("background-color: #2C3446;");
           cliente.println("}");
           cliente.println(".container th {");
           cliente.println("background-color: #1F2739;");
           cliente.println("}");

           cliente.println(".container td:first-child { color: #FB667A; }");
          
           cliente.println(".container tr:hover {");
           cliente.println("background-color: #464A52;");
           cliente.println("-webkit-box-shadow: 0 6px 6px -6px #0E1119;");
           cliente.println("-moz-box-shadow: 0 6px 6px -6px #0E1119;");
           cliente.println("box-shadow: 0 6px 6px -6px #0E1119;");
           cliente.println("}");
           cliente.println(".container td:hover {");
           cliente.println("background-color: #FFF842;");
           cliente.println("color: #403E10;");
           cliente.println("font-weight: bold;");
             
           cliente.println("box-shadow: #7F7C21 -1px 1px, #7F7C21 -2px 2px, #7F7C21 -3px 3px, #7F7C21 -4px 4px, #7F7C21 -5px 5px, #7F7C21 -6px 6px;");
           cliente.println("transform: translate3d(6px, -6px, 0);");
           cliente.println("transition-delay: 0s;");
           cliente.println("transition-duration: 0.4s;");
           cliente.println("transition-property: all;");
           cliente.println("transition-timing-function: line;");
           cliente.println("}");
           cliente.println("@media (max-width: 800px) {");
           cliente.println(".container td:nth-child(4),");
           cliente.println(".container th:nth-child(4) { display: none; }");
           cliente.println("}");
            
           cliente.println("</style>");
               
           cliente.println("<table class=\"container\">");
           cliente.println("<thead>");
           cliente.println("<tr>");
           cliente.println("<th><h1>Dispositivos Conectados</h1></th>");
           cliente.println("<th><h1>Quantidade</h1></th>");
           cliente.println("<th><h1>Disponibilidade</h1></th>");
           cliente.println("<th><h1></h1></th>");
           cliente.println("</tr>");
           cliente.println("</thead>");
           cliente.println("<tbody>");
           cliente.println("<tr>");
           cliente.println("<td>Portão Garagem</td>");
           cliente.println("<td>1</td>");
           cliente.println("<td>OK</td>");
           cliente.println("</tr>");
           cliente.println("<tr>");
           cliente.println("<td>Luzes da casa</td>");
           cliente.println("<td>4</td>");
           cliente.println("<td>OK</td>");
           cliente.println("</tr>");
           cliente.println("<tr>");
           cliente.println("<td>Ar condicionado</td>");
           cliente.println("<td>2</td>");
           cliente.println("<td>OK</td>");
           cliente.println("</tr>");
           cliente.println("</tbody>");
           cliente.println("</table>");

           //FIM DO CSS!

           cliente.println("<h1>PAINEL DE CONTROLE</h1>");
           //Botões exemplo - led 4
           cliente.println("<a href=\"/abrePortao\"\">Abrir Portão</a>");
           cliente.println("<a href=\"/fechaPortao\"\">Fechar Portão</a><br />");   
           cliente.println("<br />");     
           cliente.println("<br />"); 
           cliente.println("<br />"); 

           // led 5
           cliente.println("<a href=\"/ligaAr\"\">Ligar Ar</a>");
           cliente.println("<a href=\"/desligaAr\"\">Desligar Ar</a><br />");
           cliente.println("<br />");
           cliente.println("<br />"); 
           cliente.println("<br />");  
           
           //led 6
           cliente.println("<a href=\"/ligaLuzes\"\">Ligar Luzes</a>");
           cliente.println("<a href=\"/desligaLuzes\"\">Desligar Luzes</a><br />");
           cliente.println("<br />");
           cliente.println("<br />");
           cliente.println("<br />");

           //membros da equipe!!!!!
           cliente.println("<H2>criado e desenvolido por Arthur Pedro | Breno Medeiros | Heitor Lima | Kalécio Pereira</H2>"); 
            
           cliente.println("</BODY>");
           cliente.println("</HTML>");

           //FIM DO HTML!
     
           delay(1);
           //stopping cliente
           cliente.stop();
           //controls the Arduino if you press the buttons

           //Portão
                //se o endereço passaso for igual a "ip/abreportao/" executará esse trecho
           if (readString.indexOf("abrePortao") >0){
               digitalWrite(ledPortao, HIGH);
               Serial.println("Portão Aberto");
           }
           if (readString.indexOf("fechaPortao") >0){
               digitalWrite(ledPortao, LOW);
               Serial.println("Portão Fechado");
           }

           //Luz

            if (readString.indexOf("ligaLuzes") >0){
               digitalWrite(ledLuz, HIGH);
               Serial.println("Luzes acesas");
           }
           if (readString.indexOf("desligaLuzes") >0){
               digitalWrite(ledLuz, LOW);
               Serial.println("Luzes apagadas");
           }


            //Ar
            
            if (readString.indexOf("ligaAr") >0){
               digitalWrite(ledAr, HIGH);
               Serial.println("Ar ligado");
           }
           if (readString.indexOf("desligaAr") >0){
               digitalWrite(ledAr, LOW);
               Serial.println("Ar desligado");
           }
           
            //Limpa a string para a proxima leitura
            readString="";

            //FIM!! ?
           
         }
       }
    }
}
}
