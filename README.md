## Arbori binari de căutare

**Definiție**: Se numește arbore binar de căutare un arbore binar în care fiecare nod are o cheie unică de identificare care respectă următoarele condiții:
 - pentru orice subarbore, cheile nodurilor din subarborele stâng sunt mai mici decât cheia rădăcinii;
 - pentru orice subarbore, cheile nodurilor din subarborele drept sunt mai mari decât cheia rădăcinii.

Arborii de căutare binară permit căutarea rapidă, adăugarea și eliminarea elementelor de date. Deoarece nodurile dintr-un ABC sunt așezate astfel încât fiecare comparație sări peste aproximativ jumătate din arborele rămas, performanța căutării este proporțională cu cea a logaritmului binar. ABC-urile au fost concepute în anii 1960 pentru problema stocării eficiente a datelor etichetate și sunt atribuite lui Conway Berners-Lee și David Wheeler.

Performanța unui arbore de căutare binar depinde de ordinea de inserare a nodurilor în arbore, deoarece inserțiile arbitrare pot duce la degenerare; mai multe variante ale arborelui de căutare binar pot fi construite cu performanță garantată în cel mai rău caz. Operațiile de bază includ: căutare, parcurgere, inserare și ștergere. ABC-urile cu complexități garantate în cel mai rău caz funcționează mai bine decât o matrice nesortată, care ar necesita timp de căutare liniar.
