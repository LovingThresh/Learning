//
// Created by liuye on 2023/12/19.
//
#include <memory>
class Simple {
public:
    Simple() {m_intPtr = new int();}
    ~Simple() {delete m_intPtr;}
    void setValue(const int value) {*m_intPtr = value;}
private:
    int* m_intPtr;
};

void leaky() {
    auto* mySimplePtr {new Simple()};
    mySimplePtr->setValue(5);
    delete mySimplePtr;
}

void notleadky() {
    const auto mySimpleSmartPtr {std::make_unique<Simple>()};
    mySimpleSmartPtr->setValue(5);
}