

template <typename T> 
class Array
{
    private :
        T* element;   // Array of type T
        size_t count; // Number of array elements
    public :
        explicit Array(size_t arraySize);  // Constructor
        Array(const Array& other);         // CopyConstructor
        Array(Array&& other);              // MoveConstructor
        virtual ~Array();                  // Destructor
        T& operator[](size_t index) const; // Subscript operator
        const T& operator[](size_t index) const; // Subscript operator-const

        Array& operator = (const Array& rhs); // Assignment operator
        Array& operator = (Array&& rhs);      // Move assignment operator
        size_t size(){return count;}          // Accessor for count
};