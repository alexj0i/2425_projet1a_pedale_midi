# Revue du 07/03/2025
## Généralités
* Il faut commencer à remplir le README : 
    * À minima ajoutez vos noms, 
    * Et une description de ce qu'on trouve dans les différents dossisers
* Retirer les backups des commits avec un fichier ```.gitignore```
* Installez STM32CUBEMX
    * Créez un fichier .ioc et ajoutez le au git

## Schéma 
* Ajouter capas découplage STM32 (cf doc, 3x100nF + 1x4.7uF)
* Idem AOP MCP6002 (1x100nF)
* Connecteur pour sonde de programmation : 
    * Signaux SWD + UART RX/TX
    * Symbole : ```Conn_ST_STDC14```
    * Empreinte : ```Connector_PinHeader_1.27mm:PinHeader_2x07_P1.27mm_Vertical_SMD```
* Ajouter des points de tests :
    * Signal analogique pédale
    * Sybome : ```TestPoint```
    * Empreinte : ```TestPoint:TestPoint_Pad_D2.0mm```
* Remplacer R1 R_variable par un potentiomètre comme sur le schéma original
    * Voir avec Patricia quelle ref utiliser
    * Ou prévoir une commande
* MIDI
    * Prévoir UART,
    * Schéma selon les slides sur moodle.
* Connecteur pour l'alimentation
    * Symbole : ```Conn_01x02```
    * Empreinte : ```Connector_JST:JST_XH_S2B-XH-A_1x02_P2.50mm_Horizontal```