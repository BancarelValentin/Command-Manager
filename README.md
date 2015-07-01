Projet QtMobile : App de gestion de commandes SSH
=================================================

##Descriptif du projet

Imaginez un monde où l'on peut controller son ordinateur via son téléphone, où l'on peut mettre en route son grille-pain (en partant du principe qu'il est branché avec un serveur) depuis son canapé... Un monde sans fil entièrement personnalisable. Grâce à notre application... ***ENTREZ DANS LE FUTUR***.

A la genèse du projet, l'application servait à éxécuter des commandes SSH via une adresse IP. La connection SSH étant trop longue à implémenter nous nous sommes concentré sur la base du projet, soit la gestion des commandes.

Afin de ne pas perdre cette idée première et de ne pas tomber dans une application ridicule de type "bloc-note", nous avons simulé l'execution des commandes par un sublimissime logging dans la console.

##Descriptif des pages

* **MainPage** : c'est la page de démmarage. On y trouve la liste de toutes nos commandes SSH. Les différentes autres pages sont accessibles via le *PullDownMenu*.
* **CommandDetail** : permet d'accès aux détails d'une commande.
* **NewCommand** : permet de créer une nouvelle commande SSH avec un titre.
* **Settings** : permet de modifier l'adresse IP de la machine à laquelle on souhaite se connecter en SSH *(juste pour le fun du coup !)*.

##Les Fonctionnalités

* **Serialisation** : l'application permet de sauvegarder l'ensemble des commandes SSH dans le téléphone (au format json). Au départ, nous voulions que cette sauvegarde soit effectuée avant l'arrêt de l'application; or nous n'avons pas réussi à la faire fonctionner car la méthode n'est pas appelée (voir TP3-Sailfish.qml, ligne 48). Du coup nous avons décidé de laisser le choix à l'utilisateur via le *PullDownMenu* de la MainPage.
* **Edition d'une commande** : possibilité de modifier une commande via le menu contextuel.
* **Suppression d'une commande** : possibilité de supprimer une commande via le menu contextuel *(pas très original mais bon)*.
* **Raccourcis** : possibilité d'executer la première ou seconde commande de la liste via la Cover.