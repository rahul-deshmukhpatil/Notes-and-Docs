Map
	key_type
	mapped_type
	value_type

	insert(init_list)
	insert_range(range)

	insert_or_assign()
	emplace() -> args might construct pair<K,T>, and key, values will be destroyed if not inserted

	emplace_hint

	try_emplace(k, value_args...) : efficient than emplace

	merge
	extract
	swap

