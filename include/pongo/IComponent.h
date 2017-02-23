#pragma once

class IComponent
{
public:
	virtual ~IComponent() = default;

	// Forbid copying
	IComponent(IComponent const &) = delete;
	IComponent & operator=(IComponent const &) = delete;

	 virtual void update() = 0;

protected:
	// Allow construction for child classes only
	// IComponent();

private:

};

