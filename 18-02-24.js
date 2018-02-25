// This problem was asked by Google.
//
// Given the root to a binary tree, implement serialize(root), which serializes
// the tree into a string, and deserialize(s), which deserializes the string
// back into the tree.

function serialize(root) {
  const arr = new Array();
  buildArr(root, arr);
  return arr.join('|');
}

function buildArr(root, arr) {
  if (root === null) {
    arr.push('null');
  } else {
    arr.push(root.val);
    buildArr(root.left, arr);
    buildArr(root.right, arr);
  }
}

function deserialize(data) {
  return buildTree(data.split('|'));
}

function buildTree(arr) {
  const val = arr.shift();
  if (val === 'null') {
    return null;
  }
  const node = {
    val: parseInt(val),
    left: buildTree(arr),
    right: buildTree(arr)
  };
  return node;
}

const tree = {
  val: 1,
  left: {
    val: 2,
    left: null,
    right: {
      val: 3,
      left: null,
      right: null
    }
  },
  right: {
    val: 4,
    left: null,
    right: null
  }
};

console.log(serialize(tree));
console.log(deserialize(serialize(tree)));
