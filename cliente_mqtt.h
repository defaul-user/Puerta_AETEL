 
  #ifndef CLIENTE_MQTT_H
  #define CLIENTE_MQTT_H

    #include <PubSubClient.h>
    #include "hardware.h"

    
    /* IP del BROKER MQTT (Raspberry en nuestro caso) */
    
    const char* mqtt_server = "IP PUERTA";
    const char* mqtt_server_user = "USUARIO SERVER";
    const char* mqtt_server_password = "CONTRASEÑA SERVER";

    
    /* Cliente ESP8266 (MQTT) */
    
    WiFiClient espClient;
    PubSubClient client(mqtt_server,'PUERTO MQTT SERVER',espClient); // XXXXXXX es el puerto listener para el Broker
    //const char* clientID = "ESP8266_1";
    uint8_t intentos_conexion = 0; // Contador q usaremos para limitar el nº de intentos de conexion a la red wifi
    
    
    /* Variables correspondientes a los TOPIC SUB y PUB ( MQTT ) */
    
    const char* topic_subs_puerta = "TOPIC PUERTA"; // Variable Correspondiente al ACTUADOR LA PUERTA


    /* Cabeceras de las funciones */
    
    void callback(char* topic, byte* payload, unsigned int length); // Funcion callback para los mensajes entrantes (llamadas) mqtt
    void reconnect(); // Funcion para reconectar en caso de perderse la conexion con el broker mqtt
    void arrancar_cliente_mqtt();
    void manejadorClienteMQTT();
  
  #endif
