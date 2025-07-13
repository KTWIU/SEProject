# Aufgabenplaner (C++ / Qt)

Einfache Desktop-Anwendung zum Verwalten von Aufgaben, geschrieben in C++ mit Qt.

## Features

- Aufgaben anlegen, bearbeiten, als erledigt markieren und löschen
- Anzeige von offenen, erledigten und überfälligen Aufgaben
- Speicherung der Aufgaben in einer Datei (.csv)
- Einfache grafische Benutzeroberfläche (Qt)

## Installation & Start

1. Projekt im Qt Creator oder mit CMake öffnen.
2. Kompilieren (benötigt Qt5 oder Qt6).
3. Nach dem Kompilieren im Build-Ordner das Tool `windeployqt` auf die erzeugte .exe anwenden Dadurch werden alle benötigten Qt-Bibliotheken und Plugins in denselben Ordner kopiert.
4. Die Anwendung lässt sich nun direkt durch Doppelklick auf die EXE starten, es ist keine weitere Installation erforderlich.

## Hinweise

- Alle Aufgaben werden im Programmordner in einer csv-Datei gespeichert.
- Weitere Infos zur Architektur und Bedienung befinden sich in der Projektdokumentation (PDF).

