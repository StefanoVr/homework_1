# HOMEWORK 1
Università degli Studi di Verona

Corso di Robotica - Laboratorio Ciberfisico

# Istruzioni
```
roslaunch homework_1 homework_1.launch
```
Dettagli:
Utilizzando le guide proposte durante il corso è stato sviluppato il seguente progetto.

homework_1/msg/ 
'Keyboard.msg' -> Gestione Input da Tastiera 
- uint8; 
'Studente.msg' -> Gestione dei dati relativi allo studente 
- string nome_studente - rappresentazione del nome dello studente
- uint8 eta - rappresentazione dell'età dello studente                     
- string corso - rappresentazione del corso
- string testo_concat - rappresentazione della stringa intera
/src/
'keyboard_pub.cpp' # Gestione input da tastiera 
'a' -> tutta la stringa; 
'c' -> corso; 
'e' -> età dello studente; 
'n' -> nome dello studente. 
Warning: la gestione dell'input è stata realizzata tenendo conto che la funzione di input da
tastiera non sia bloccante - inteso che basta digitare il uno dei tasti richiesti per eseguir
l'operazione di input.
'pub_student.cpp' # Gestione delle informazioni relative allo studente
'Listener_Msg'    # Gestione dell'ascoltatore e produzione dell'output a video

(Publisher) keyboard_pub  -> (topic) msg_cmd 
(Publisher) pub_student   -> (topic) msg_dati 

Listener.msg/ 
  Subscriber sub1 = n1.subscribe(msg_cmd, 1000, chatterCallback);
  Subscriber sub2 = n2.subscribe(msg_dati, 1000, chatterCallback_DATA);

NOTE:
  L'assegnamenti di sub1 e sub2 presentano lo stesso nodo 'n1' in quanto l'iscrizione al tipic parte da un'unico Subscriber
  (Listener_Msg.cpp) 

  Per stampa del grafico:
                          ~$ rqt_graph
