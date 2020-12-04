# Lab_final

Sistema de monitoreo para las siguientes características de un motor de corriente
alterna:

• Velocidad.
• Frecuencia.
• Voltaje.
• Temperatura.
• Tiempo de operación.

El sistema de monitoreo consiste en una Interfaz de Usuario (UI) desde donde se visualizan los
parámetros del motor y se controla un proceso de comunicación. Este último, encargado de pedir
los valores de referencia y tolerancia de las variables; y los valores actualizados a un software que
los tiene disponibles. La solicitud de los valores de referencia y tolerancia se hace mediante el envío
de la palabra “referencia_tolerancia:” seguido del número del carné. Por su parte, los valores
actualizados del motor se entregan siempre que se envíe la palabra “motor1:” acompañado de su
número de carné en la solicitud.

- Solicitud de valores de referencia y tolerancia: “referencia_tolerancia:220XXXX”
- Solicitud de valores actualizados del motor: “motor1:220XXXX”
