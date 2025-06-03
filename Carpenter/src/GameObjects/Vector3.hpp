namespace PotionParts {

class Vector3 {
public:

   /// @breif constructs a Vector3 with zero for all aspects
   Vector3();

   /// @brief constructs a Vector3 with the specified X, Y, and Z coordinates
   Vector3(float x, float y, float z);

   /// @brief gets the x value
   float x();

   /// @brief gets the y value
   float y();

   /// @brief gets the z value
   float z();

   /// @brief sets the x value
   void xIs(float x);

   /// @brief sets the y value
   void yIs(float y);

   /// @brief sets the z value
   void zIs(float z);

   /// @brief sets all 3 values
   void set(float x, float y, float z);
private:

   float _x;
   float _y;
   float _z;

};

} //PotionParts