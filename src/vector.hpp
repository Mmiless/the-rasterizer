template<typename T> 
class Vec2 {
public:

    Vec2(): x(0), y(0) {}
    Vec2(T x): x(x), y(x) {}
    Vec2(T x, T y): x(x), y(y) {}

    Vec2(Vec2<T>& other){
        x = other.x;
        y = other.y;
    }

    Vec2 operator+(const Vec2& other){
        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2& other){
        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(const T& r){
        return Vec2(x * r, y * r);
    }

    Vec2 operator/(const T& r){
        return Vec2(x / r, y / r);
    }

    Vec2 operator==(const Vec2<T>& other){
        return (x == other.x && y == other.y);
    }

    T x, y;
};

typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;

template<typename T> 
class Vec3 {
public:

    Vec3(): x(0), y(0), z(0) {}
    Vec3(T x): x(x), y(x), z(x) {}
    Vec3(T x, T y, T z): x(x), y(y), z(z) {}

    Vec3(Vec3<T>& other){
        x = other.x;
        y = other.y;
        z = other.z;
    }

    Vec3 operator+(const Vec3& other){
        return Vec2(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3& other){
        return Vec2(x - other.x, y - other.y, z - other.z);
    }

    Vec3 operator*(const T& r){
        return Vec2(x * r, y * r, z * r);
    }

    Vec3 operator/(const T& r){
        return Vec2(x / r, y / r, z / r);
    }

    Vec3 operator==(const Vec3<T>& other){
        return (x == other.z && y == other.y && z == other.z);
    }

    T x, y, z;
};

typedef Vec3<int> Vec3i;
typedef Vec3<float> Vec3f;
