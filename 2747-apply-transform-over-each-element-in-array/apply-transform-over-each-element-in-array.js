var map = function(arr, fn) {
  const result = [];
  for (let i = 0; i < arr.length; i++) {
    const transformedValue = fn(arr[i], i);
    result.push(transformedValue);
  }
  return result;
};
