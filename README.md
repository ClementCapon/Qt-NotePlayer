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

[Capture vidéo du 2025-01-07 09-17-11.webm](https://github.com/user-attachments/assets/149c42fa-65f9-4070-8997-d6b7f34db71d)


3. Préparation du Code

      - Clonez ce dépôt

            git clone https://github.com/ClementCapon/Qt-NotePlayer.git
            cd Qt-NotePlayer

      - Modifier l'adresse IP de connexion MySQL

      - Dans main.cpp, modifiez l'adresse de connexion avec celle de votre serveur MySQL (remplacez 127.0.0.1 par votre adresse réseau si nécessaire). Exemple :

            db.setDatabaseName("NoteJoueur");
            ...
            db.setUserName("votre_nom_d'utilisateur");
            db.setPassword("votre_mdp");
        
        - Mettez un autre identifiant que root car cela peut poser des problèmes à la connexion entre le code et la base de données.

4. Compilation et Exécution

      - Pour compiler et exécuter sur Qt, c'est très simple, tapez *CTRL + R* 

5. Dépannage des erreurs de connexion

      - Assurez-vous que le serveur MySQL est démarré :

            sudo service mysql start
            Vérifiez que l'adresse et le port sont corrects.

      - Si nécessaire, configurez MySQL pour accepter les connexions réseau en modifiant /etc/mysql/mysql.conf.d/mysqld.cnf et en commentant bind-address avec #. Redémarrez ensuite MySQL :

            sudo service mysql restart
