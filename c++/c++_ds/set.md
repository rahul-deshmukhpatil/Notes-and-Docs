
contains(X x) : Compare::is_transparent allows calling compare without constructing keys

merge(source continer): merge (by extracting not copying or moving) nodes from another container into *this.
						if key is already present is checked by Compare of *this.
						if key is present, nodes are not extracted.
						behavior is undefined if allocators are not equal
