#include <iostream>
#include <memory>

int main() {
    // 1. Creating and initializing a unique_ptr
    std::unique_ptr<int> uptr1(new int(10));
    std::cout << "unique_ptr value: " << *uptr1 << std::endl;

    // 2. Transferring ownership with std::move
    std::unique_ptr<int> uptr2 = std::move(uptr1);
    std::cout << "Transferred ownership, unique_ptr2 value: " << *uptr2 << std::endl;
    if (!uptr1) std::cout << "Not a valid pointer - uptr1" << std::endl; 

    // 3. Releasing the managed object and resetting the unique_ptr
    int* rawPtr = uptr2.release();
    std::cout << "Released uptr2, raw pointer value: " << *rawPtr << std::endl;
    // We need to delete rawPtr manually
    delete rawPtr;

    // 4. When reset to new memory, any older memory if was present would be deleted
    //    We already released it in this example.
    uptr2.reset(new int(20));
    std::cout << "Reset unique_ptr2 with new value: " << *uptr2 << std::endl;

    // 5. Using a custom deleter with unique_ptr
    auto customDeleter = [](int* ptr) {
        std::cout << "Custom deleter called for " << *ptr << std::endl;
        delete ptr;
    };

    std::unique_ptr<int, decltype(customDeleter)> uptr3(new int(30), customDeleter);
    std::cout << "unique_ptr with custom deleter value: " << *uptr3 << std::endl;

    std::cout << "program ends here" << std::endl;

    // 6. The custom deleter will be called when uptr2 goes out of scope
    // 7. Automatically deallocating memory when unique_ptr goes out of scope
    return 0;
}

