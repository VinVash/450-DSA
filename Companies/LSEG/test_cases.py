# Test cases for solution(A, B)
# Expected output: minimal value that occurs in both arrays, or -1 if no common elements

test_cases = [
    # Test case 1: Example from problem
    {
        "A": [1, 3, 2, 1],
        "B": [4, 2, 5, 3, 2],
        "expected": 2,
        "description": "Example 1: Common elements are 2 and 3, minimum is 2"
    },
    
    # Test case 2: Example from problem
    {
        "A": [2, 1],
        "B": [3, 3],
        "expected": -1,
        "description": "Example 2: No common elements"
    },
    
    # Test case 3: Single common element
    {
        "A": [5, 7, 9],
        "B": [1, 3, 5],
        "expected": 5,
        "description": "Single common element"
    },
    
    # Test case 4: Multiple common elements, minimum is first
    {
        "A": [1, 5, 10, 15],
        "B": [1, 3, 5, 7],
        "expected": 1,
        "description": "Minimum common element is 1"
    },
    
    # Test case 5: All elements common
    {
        "A": [2, 4, 6],
        "B": [6, 2, 4],
        "expected": 2,
        "description": "All elements common, minimum is 2"
    },
    
    # Test case 6: Duplicates in both arrays
    {
        "A": [3, 3, 3, 5, 5],
        "B": [3, 5, 5, 7],
        "expected": 3,
        "description": "Duplicates present, minimum common is 3"
    },
    
    # Test case 7: Zero as common element
    {
        "A": [0, 1, 2, 3],
        "B": [0, 4, 5],
        "expected": 0,
        "description": "Zero is the minimum common element"
    },
    
    # Test case 8: No common elements
    {
        "A": [1, 2, 3],
        "B": [4, 5, 6],
        "expected": -1,
        "description": "No common elements"
    },
    
    # Test case 9: Single element arrays, common
    {
        "A": [7],
        "B": [7],
        "expected": 7,
        "description": "Single element arrays with common element"
    },
    
    # Test case 10: Single element arrays, not common
    {
        "A": [5],
        "B": [10],
        "expected": -1,
        "description": "Single element arrays with no common element"
    },
    
    # Test case 11: Large arrays with common elements
    {
        "A": [10, 20, 30, 40, 50],
        "B": [5, 15, 25, 30, 35, 45],
        "expected": 30,
        "description": "Large arrays, common element is 30"
    },
    
    # Test case 12: Minimum at end of sorted arrays
    {
        "A": [100, 200, 300],
        "B": [50, 150, 250, 300],
        "expected": 300,
        "description": "Common element is the largest in both"
    },
    
    # Test case 13: Multiple duplicates, minimum common
    {
        "A": [1, 1, 1, 2, 2, 3],
        "B": [1, 2, 2, 2, 4],
        "expected": 1,
        "description": "Many duplicates, minimum common is 1"
    },
    
    # Test case 14: Unsorted input (function sorts internally)
    {
        "A": [9, 1, 5, 3, 7],
        "B": [2, 5, 8, 1, 4],
        "expected": 1,
        "description": "Unsorted arrays, minimum common is 1"
    },
    
    # Test case 15: Common element appears multiple times
    {
        "A": [5, 5, 5, 5],
        "B": [5, 5],
        "expected": 5,
        "description": "Same element repeated in both arrays"
    },
    
    # Test case 16: Different sized arrays
    {
        "A": [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
        "B": [5],
        "expected": 5,
        "description": "Very different array sizes"
    },
    
    # Test case 17: All zeros
    {
        "A": [0, 0, 0],
        "B": [0, 0],
        "expected": 0,
        "description": "All zeros"
    },
    
    # Test case 18: Large numbers
    {
        "A": [1000, 2000, 3000],
        "B": [500, 1500, 2000, 2500],
        "expected": 2000,
        "description": "Large numbers, common element is 2000"
    },
    
    # Test case 19: Minimum common is in middle
    {
        "A": [10, 20, 30, 40],
        "B": [5, 20, 25, 35],
        "expected": 20,
        "description": "Common element in middle of ranges"
    },
    
    # Test case 20: Complex case with many elements
    {
        "A": [1, 3, 5, 7, 9, 11, 13, 15],
        "B": [2, 4, 6, 8, 10, 12, 14, 16],
        "expected": -1,
        "description": "Many elements but no common values"
    }
]

# Function to run all test cases
def run_tests():
    from main import solution
    
    passed = 0
    failed = 0
    
    print("Running test cases...\n")
    
    for i, test in enumerate(test_cases, 1):
        A = test["A"]
        B = test["B"]
        expected = test["expected"]
        description = test["description"]
        
        result = solution(A.copy(), B.copy())  # Use copy to avoid modifying original
        
        if result == expected:
            print(f"✓ Test {i}: PASSED - {description}")
            print(f"  A = {A}, B = {B}")
            print(f"  Expected: {expected}, Got: {result}\n")
            passed += 1
        else:
            print(f"✗ Test {i}: FAILED - {description}")
            print(f"  A = {A}, B = {B}")
            print(f"  Expected: {expected}, Got: {result}\n")
            failed += 1
    
    print(f"\n{'='*60}")
    print(f"Total: {len(test_cases)} tests")
    print(f"Passed: {passed}")
    print(f"Failed: {failed}")
    print(f"{'='*60}")

if __name__ == "__main__":
    run_tests()

