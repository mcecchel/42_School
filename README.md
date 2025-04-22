get_next_line è un progetto della Scuola 42 che ha l’obiettivo di implementare una funzione in C capace di leggere e restituire, riga per riga, il contenuto di un file aperto tramite file descriptor. Questo esercizio approfondisce:

    > Gestione avanzata dei file descriptor: lettura controllata, riconoscimento di End-Of-File (EOF) e gestione degli errori.

    > Buffering efficiente: utilizzo di buffer di dimensione definita per minimizzare le chiamate di sistema read.

    > Memoria dinamica: allocazione e deallocazione sicura per costruire le righe di output, evitando perdite di memoria.

Funzionalità implementate

    - get_next_line(int fd): restituisce la riga successiva dal file descriptor fd, inclusivo del carattere di newline (\n), oppure NULL a EOF o in caso di errore.

    - Supporto per letture parziali: gestisce file in cui la lunghezza delle righe è maggiore del BUFFER_SIZE.

    - Gestione multipla di file descriptor: mantiene uno stato indipendente per ogni fd aperto contemporaneamente.
