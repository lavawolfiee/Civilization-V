# Civilization-V

## Описание

Civilization-V - пошаговая стратегия, ремейк одноименной игры от компании Feraxis

## Установка

### Linux
```
sudo apt install libsfml-dev

sudo add-apt-repository ppa:texus/tgui
sudo apt update
sudo apt install libtgui-0.9-dev
```

### Windows

Под винду установка сложнее, так как библиотеки очень сложно подгружаются

## Сборка

```
mkdir build && cd build
cmake .. && make -j9
```

## Запуск

```

```

## Прогресс

На данный момент реализованы:
+ Карта и ее случайная генерация с помощью шумов
+ Редактор карты
+ Юниты, ходьба и смена хода
+ Взаимодействие юнитов: атака юнитами ближнего и дальнего боя

##  UML

[Общая схема](https://app.creately.com/diagram/3FwxQh5iohh)

[Схема AbstractFactory](...)

## Паттерны

[AbstractFactory](https://github.com/lavawolfiee/Civilization-V/blob/dev/units/Factory.h#L10-L20)

[Facade](https://github.com/lavawolfiee/Civilization-V/blob/dev/gui/GUI.h#L10)

[Decorator](https://github.com/lavawolfiee/Civilization-V/blob/dev/gui/Batch.h#L7-L18)

[Command](https://github.com/lavawolfiee/Civilization-V/blob/dev/gui/GUI.h#L43-L54)

