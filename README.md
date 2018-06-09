# HOMEWORK 1
Università degli Studi di Verona

Corso di Robotica - Laboratorio Ciberfisico

# ISTRUZIONI
```
roslaunch homework_1 homework_1.launch
```
# DETTAGLI
Utilizzando le guide proposte durante il corso è stato sviluppato il seguente progetto

> [Testo HOMEWORK1](http://profs.scienze.univr.it/~bloisi/corsi/homework/homework-1.pdf)

## /msg/Keyboard.msg
Gestione del messaggio
- uint8
- string msg

## /msg/Studente.msg 
Gestione dei dati relativi allo studente

- string nome_studente - rappresentazione del nome dello studente
- uint8 eta - rappresentazione dell'età dello studente                     
- string corso - rappresentazione del corso
- string testo_concat - rappresentazione della stringa intera

## /src/keyboard_pub.cpp
Stampa nel topic i caratteri inseriti da tastiera
- a: tutta la stringa
- c: corso 
- e: età dello studente
- n: nome dello studente

```
(Publisher) keyboard_pub  -> (topic) msg_cmd
```

> Warning: la gestione dell'input è stata realizzata tenendo conto che la funzione di input da
> tastiera non sia bloccante - inteso che basta digitare il uno dei tasti richiesti per eseguir
> l'operazione di input.

## /src/pub_student.cpp 
Stampa dei dati relativi allo studente
```
(Publisher) pub_student   -> (topic) msg_dati
```
## /src/Listener_Msg
Ascoltatore dei Topic
```
Subscriber sub1 = n1.subscribe(msg_cmd, 1000, chatterCallback)
Subscriber sub2 = n2.subscribe(msg_dati, 1000, chatterCallback_DATA)
```
# NOTE
L'assegnamenti di sub1 e sub2 presentano lo stesso nodo 'n1' in quanto l'iscrizione al tipic parte da un'unico Subscriber
(Listener_Msg.cpp) 

Per stampa del grafico:
```
~$ rqt_graph
```

# AUTORE
Stefano Veraldi  - VR378035

