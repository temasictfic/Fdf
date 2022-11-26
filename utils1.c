int err_calc(t_p *delta)
{
	return (((delta->x > delta->y) * delta->x / 2) - (delta->x <= delta->y) * delta->y / 2);
}

