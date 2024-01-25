#include <iostream>
#include <vector>

// Базовий клас Component, що визначає інтерфейс для всіх об'єктів (листків та складних)
class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};

// Листок (кінцевий об'єкт)
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation\n";
    }
};

// Складний об'єкт (містить в собі листки та/або інші складні об'єкти)
class Composite : public Component {
public:
    void add(Component* component) {
        components_.push_back(component);
    }

    void operation() const override {
        std::cout << "Composite operation\n";
        for (const auto& component : components_) {
            component->operation();
        }
    }

private:
    std::vector<Component*> components_;
};

int main() {
    // Використання паттерна "Компонувальник"
    Leaf leaf1, leaf2;
    Composite composite1, composite2;

    // Додавання листків до складного об'єкту
    composite1.add(&leaf1);
    composite1.add(&leaf2);

    // Додавання складного об'єкту та листка до іншого складного об'єкту
    composite2.add(&composite1);
    composite2.add(&leaf1);

    // Виклик операції на складному об'єкті, який включає інші об'єкти
    composite2.operation();

    return 0;
}
