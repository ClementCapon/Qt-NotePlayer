# Qt-NotePlayer

1. Prérequis

      - Assurez-vous d'avoir les éléments suivants installés :

      - Qt Creator
  
        - Vous pouvez l'installer directement sur leur site : https://www.qt.io/download-dev

      - MySQL Server

            sudo apt install mysql-server
            sudo service mysql start

2. Configuration de la Base de Données

      - Se connecter à MySQL Connectez-vous au serveur MySQL :

            sudo mysql -u nom_utilisateur -p

      - Entrez votre mot de passe de votre nom d'utilisateur pour MySQL.

      - Créer la base de données Dans le terminal MySQL, exécutez les commandes suivantes pour créer la base de données et la table d'équipements :

            CREATE DATABASE NoteJoueur;
            USE NoteJoueur;

            CREATE TABLE Joueur (
                id INT AUTO_INCREMENT PRIMARY KEY,
                nom VARCHAR(50),
                club VARCHAR(50),
                note INT
            );

      - Si vous souhaitez utilisez le fichier notejoueur.sql, executez cette commande dans le terminal : 

            mysql -u nom_utilisateur -p NoteJoueur < notejoueur.sql
        
      - Sinon, executez ceci dans MySQL :
        
            INSERT INTO Joueur (nom, club, note)
            VALUES ('...', '...' , ... ),
                   ('...', '...' , ...),
                   ('...', '...' , ...);

        - Remplacez les pointilliers par ce que vous voulez tout en respectant ( VARCHAR, VARCHAR, INT )

3. Préparation du code

   
