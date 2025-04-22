ft_printf è un progetto della Scuola 42 volto a ricreare la celebre funzione printf della libreria C standard, supportando un sottoinsieme di specificatori di formato e gestendo in autonomia tutte le conversioni e la stampa. Questo progetto approfondisce:

    > Parsing di stringhe di formato: analisi carattere per carattere, riconoscimento di flag, width, precision e specifier.

    > Gestione variadica degli argomenti: utilizzo di stdarg.h per processare un numero variabile di parametri.

    > Conversione e formattazione: trasformazione di numeri interi, puntatori e stringhe nei rispettivi formati testuali, con supporto a flag come -, 0, ., width e precision.

    > Output sicuro e efficiente: scrittura su STDOUT tramite chiamate write, minimizzando le operazioni di I/O e gestendo errori.

Specificatori supportati

    Caratteri e stringhe: %c, %s

    Interi decimali e interi con segno: %d, %i, %u

    Esadecimali: %x, %X, con gestione di prefisso 0x/0X quando richiesto

    Puntatori: %p

    Percentuale letterale: %%
