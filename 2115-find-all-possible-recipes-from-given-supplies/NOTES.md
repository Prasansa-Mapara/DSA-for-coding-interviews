here i cant directly use topo sort, because we also have to check the supplies, if some element is there in ing but not in sup, then we can't consider that element.
We can only take the elements that are in sup, and which doesn't require any other ing to prepare itself, hence indeg should be 0;
​