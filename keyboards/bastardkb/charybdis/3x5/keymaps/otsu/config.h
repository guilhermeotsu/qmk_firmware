// Mouse Acceleration Curve parameters to map input-velocity [0, 100+] to a velocity-factor [1, 10+],
// as seen in https://www.desmos.com/calculator/xkhejelty8
#define MACCEL_TAKEOFF 2.0      // (K) --/++ curve starts rising smoothlier/abruptlier
#define MACCEL_GROWTH_RATE 0.25 // (G) --/++ curve reaches max limit slower/faster
#define MACCEL_OFFSET 2.2       // (S) --/++ growth kicks in earlier/later
#define MACCEL_LIMIT 6.0        // (M) maximum acceleration factor
