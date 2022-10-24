#ifndef DEBUG_H
#define DEBUG_H

#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief A class that can be implemented to use him in the debug implementation.
 */
class debugable_class {
   public:
    /**
     * @brief Abstract method to be implemented by the derived class.
     */
    virtual void print() = 0;
};

/**
 * @brief A class to convert a type to a debugable object.
 */
template <typename T>
class debugable : public debugable_class {
   public:
    /**
     * @brief Construct a new debugable object
     *
     * @param The pointer to the object to be debugged
     */
    debugable(T* reference) : reference(reference) {}

    /**
     *  @brief Destroy the debugable object
     */
    ~debugable() {}

    /**
     *  @brief Print the object to the console
     */
    void print() { std::cout << *reference; }

    /**
     *  @brief Get the object
     *
     *  @return The pointer to the object
     */
    std::string getName() { return name; }

   private:
    /**
     * @brief The name of the object
     */
    std::string name;

    /**
     * @brief  The pointer to the object
     */
    T* reference;
};

/**
 * @brief Struct to store the debug information
 */
typedef struct debugable_struct {
    debugable_class* debugable;
    std::string name;
} debugable_struct;

/**
 * @brief A class to debug the program
 */
class Debug {
   private:
    std::stringstream ss;
    static std::vector<debugable_struct> data;

   public:

    /**
     * @brief Construct a new Debug object
     */
    Debug();

    /**
     * @brief add a new object object to the debug
     * 
     * @param name The name of the object
     * @param debugable The object to be debugged
     */
    static void add(debugable_class* ref, std::string name);

    /**
     * @brief Print the debug information to the console
     * 
     * @param split Split the debug information in multiple lines
     */
    static void breakPoint(bool split);
};

#endif