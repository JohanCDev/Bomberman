# ECS utilisation

Simple usage of ecs system.

## Getting Started With Entity

### Create world variable

* This variable will store all entities and systems.
```
ecs::World world;
```

### Create entity

* Just declare variable normally.
* An entity is a unique_ptr so declare it as follow:
```
std::unique_ptr<ecs::Entity> entity = std::make_unique<ecs::Entity>();
```

### Add a component to an entity

* Use the addComponent method present in entity class.
* Each component take a variadic number of arguments. The following list is all differents components with their constructor:
```
ecs::Transform -> float posX, float posY, float posZ, float speedX, float speedY, float speedZ
ecs::Player -> std::string texturePath, float radius, Color color
ecs::Wall -> std::string texturePath, float height, float width, Color color
ecs::Circle -> std::string texture, float radius, Color color
ecs::Rectangle -> std::string texture, float height, float width, Color color
ecs::Text -> std::string text, float textSize, Color color
```

* To use the addComponent method you have to specify the type of component you want to use and after give the differents parameters
* The following exemple will add Player component without texture:
```
entity->addComponent<   >("", static_cast<float>(2.0), BLACK);
```

* If you want to add a texture you have to write the file path in the first parameter and use static_cast for every float.

### Add the entity to the world

* Add the entity by using the world addEntity method.
```
world.addEntity(std::move(entity));
```

### Has component

* You can verify if an entity have a specific component. Return a boolean.
* For exemple, you want to know if the entity have a transform component, the following line will tell you if this component is present:
```
entity->hasCompoType(ecs::compoType::TRANSFORM);
```

### Get specific component

* In some case, you may want to use a specific component. Return a pointer of the type you asking for.
* For exemple, if you want to get the Transform component use the following line. Specify the type of component you want to have:
```
ecs::Transform *transformCompo = entity->getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
```

### Display all entities

* You can use the draw method present in every entity as follow:
```
for (auto &ent : world.entities) {
    ent->draw(ecs::drawableType::D2);
}
for (auto &ent : world.entities) {
    ent->draw(ecs::drawableType::D3);
}
```

## Getting Started With System

### What is a system ?

* A System is a class who will give life and physics to entity (ex: Movement or collisions)
* For exemple, movement system take the transform component of the entity (only if he can) and then increment the entity postion with the speed value of transform component.

### Storage of system

* The system is also store in the world variable previously created

### Create systems

* To create all systems you have to use the world createSystem method, it will created every systems:
```
world.createSystem()
```

### Update systems

* Every system have is own update method and take the entities array in parameters.
```
for (auto &system : world.systems) {
    system->update(world.entities);
}
```
