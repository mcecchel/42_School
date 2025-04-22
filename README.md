push_swap è un progetto della Scuola 42 che richiede di sviluppare un algoritmo per ordinare una lista di numeri interi utilizzando esclusivamente due pile (stack) e un insieme limitato di operazioni: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb e rrr. L’obiettivo è minimizzare il numero di operazioni eseguite, ottimizzando così la complessità dell’algoritmo e la sua efficienza.
Operazioni consentite

    Swap

        sa, sb: scambia i primi due elementi di stack a o stack b

        ss: sa e sb simultanei

    Push

        pa: sposta l’elemento in cima a stack b su stack a

        pb: sposta l’elemento in cima a stack a su stack b

    Rotate

        ra, rb: sposta il primo elemento di stack a o stack b alla fine

        rr: ra e rb simultanei

    Reverse rotate

        rra, rrb: sposta l’ultimo elemento di stack a o stack b in cima

        rrr: rra e rrb simultanei

Funzionalità implementate

    - Lettura degli argomenti da linea di comando e validazione degli input (numeri interi, senza duplicati).

    - Algoritmo di ordinamento basato su approccio dimensionale (divisione in chunk) o su ricerca del percorso ottimale.

    - Generazione della sequenza di operazioni ottimale o quasi ottimale per l’ordinamento.

    - Funzioni di supporto per la gestione delle pile: push, pop, swap, rotate, reverse rotate.
